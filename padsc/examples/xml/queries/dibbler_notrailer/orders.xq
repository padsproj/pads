{-- Orders with given start date --}
{-- Dates are not yet implemented in Galax --}
<Q1>
{ $dibbler/dibbler/order[event[1][timeStamp = 957499200]] }
</Q1>; 

{-- Orders for selected customers --}
<Q2>
{ $dibbler/dibbler/order[header/serviceTN = "7182578997"] } 
</Q2>; 

{-- Orders containing given state --}
<Q3>
{ $dibbler/dibbler/order[event/state = "19"] } 
</Q3>; 

{-- Orders from geographic location. --}
<Q4>
{ $dibbler/dibbler/order[zip = "11798"]
</Q4>; 

{-- Orders active for more than a certain length of time --}
<Q5>
{ $dibbler/dibbler/order[event[last()]/timeStamp - event[1]/timeStamp >= 55000000] }
</Q5>; 
{-- 
{ 
  for $o in $dibbler/dibbler/order
  where event[last()]/timeStamp - event[1]/timeStamp >= 55000000
  return $o
}
--}

{-- Orders that have not yet completed (not yet reached certain state)--}
{-- If there is a BILL_LOC state anywhere in stream, then it is
    completed.  "Usage" state.  --}
<Q6>
{ $dibbler/dibbler/order[event[last()]/state != "BILL_LOC"] }
</Q6>; 

{-- Orders whose first state has a timestamp within a given window. --}
<Q7>
{ $dibbler/dibbler/order[event[1][timeStamp >= 950000000 and timeStamp <= 1010000000 ]] }
</Q7>; 

{-- Orders that contain some event entering state 320 by date X and
    are still in state 320 by date Y --}
<Q8>
{ for $order in $dibbler/dibbler/order 
  where fn:exists(for $event at $i in $order/event[state = "320" and timeStamp < 1010000000]
                  where $order/event[$i+1][timeStamp < 1013000000] 
                  return $event)
  return $order
}
</Q8>; 

{-- All orders that contain states from a specified list.
    The XQuery '=' operator is existentially quantified so the query
    below selects those order that have at least one event with a
    state equal to one of 320, BILL_LD, or IE0222.  --} 
<Q1>{ 
  let $states := ("320", "BILL_LD", "IE0222")
  return $dibbler/dibbler/order[event/state = $states]
}</Q1>

