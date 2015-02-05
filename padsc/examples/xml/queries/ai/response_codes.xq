import module namespace HTTP = "http" at "../../queries/ai/http_library.xq";
declare namespace padsns="file:ai.p";
(:

  For each distinct response code in the PADS HTTP-CLF source, return
  the code number and its description, specified in the HTTP library
  module. 

:)
<codes> { 
  for $c in distinct-values(./padsns:PSource/elt/response/val)
  return 
  <code>
    <num>{$c}</num>
    <description>{ HTTP:string-of-code($c) }</description>
  </code>
} </codes>