import List
import Language.Haskell.TH
import Language.Haskell.TH.Syntax

data Format = D | S | L String
 deriving Show

parse :: String -> [Format]
parse str = parse' str "" []
 where parse' "" sa la = List.reverse ((emitString sa)++la)
       parse' ('%':'d':rs) sa la = parse' rs "" (D:((emitString sa)++la))
       parse' ('%':'s':rs) sa la = parse' rs "" (S:((emitString sa)++la))
       parse' (c:cs) sa la = parse' cs (c:sa) la
       emitString "" = []
       emitString s  = [L (reverse s)]

genb :: [Format] -> ExpQ
genb [D] = [| \n -> show n |]
genb [S] = [| \s -> s |]
genb [L s] = lift s

gen :: [Format] -> ExpQ -> ExpQ
gen []         x = x
gen (D   : xs) x = [| \n -> $(gen xs [| $x++show n|]) |]
gen (S   : xs) x = [| \s -> $(gen xs [| $x++s |]) |]
gen (L s : xs) x = gen xs [| $x ++ $(lift s) |]
      
printf :: String -> ExpQ
printf s = gen (parse s) [| "" |]