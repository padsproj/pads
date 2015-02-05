(:
declare namespace padsns = "file:dibbler_notrailer.p";
fn:count(for $e in ./padsns:PSource/elt
:)
where some $e1 in $e/events/elt,
           $e2 in $e/events/elt
      satisfies $e1/state/val = "19" and $e2/state/val = "28" and  
                $e1/tstamp/val > $e2/tstamp/val 
return $e)
