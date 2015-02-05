{-- What is average time between state x and state y? --}
<Q2>{
  let $x := "4", 
      $y := "BILL_LD"
  return
    avg(
      for $order in $dibbler/dibbler/order
      let $eventx := $order/event[state = $x][1], 
          $eventy := $order/event[state = $y][1]
      return $eventx/timeStamp - $eventy/timeStamp
    )
}</Q2>
  
{-- Identify sink states 

  real	4m27.793s
  user	2m11.630s
  sys	0m0.130s

--}
<Q4>{ 
  let $states := distinct-values(data($dibbler/dibbler/order/event/state))
  for $s1 in $states
  let $sinks :=
      (for $o1 in $dibbler/dibbler/order, 
          $e1 at $p1 in $o1/event
       where $e1/state = $s1 and count($o1/event[$p1 + 1]) = 0
       return $s1)
  where not(empty($sinks))
  return <sink>$s1</sink>
}
</Q4>;

{--  For orders that eventually got to state 5, the difference
     between between the time associated with state 4 and the
     time associated with the first usage state.
--}
<Q5>{
  for $order in $dibbler/dibbler/order[event/state = "5"]
  let $event4 := $order/event[state = "4"],
      $usage_event := $order/event[state = "BILL_LD"][1]
  return 
    <order-time>{ $usage_event/timeStamp - $event4/timeStamp }</order-time>
}</Q5>;

{-- The time associated with state 4 and the time associated with the
    first usage state.  --}
<Q6>{
  for $order in $dibbler/dibbler/order[event/state = "4"]
  let $usage_event := $order/event[state = "BILL_LD"][1]
  return 
    <order-time>
      <state-4>{ $order/event[state = "4"]/timeStamp }</state-4>
      <state-usage>{ $usage_event/timeStamp }</state-usage>
    </order-time>
}</Q6>
