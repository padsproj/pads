(:

  For each HTTP-CLF entry whose response code was 404 (an error
  occurred), return the requesting host and the requested URI. 

:)
for $e in ./padsns:PSource/elt[response/val = 404]
return 
  <illegal>  
    <host>{ $e/host/(resolved|symbolic)/elt/val }</host>
    <uri>{ fn:data($e/request/req_uri/val) }</uri>
  </illegal>




