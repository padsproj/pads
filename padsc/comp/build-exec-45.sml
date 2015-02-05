SMLofNJ.Internals.GC.messages false;
#set CM.Control.verbose false;
(* Turn on backtracing for compilation *)
(* SMLofNJ.Internals.BTrace.mode (SOME true); *)
CM.make "main.cm";
(* Turn off backtracing *)
(* SMLofNJ.Internals.BTrace.mode (SOME false); *)
Main.emit true
