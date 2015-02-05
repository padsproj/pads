{--  Number of orders that got to state 5. --}
<Q2>
{ count($dibbler/dibbler/order[event/state = "5"]) }
</Q2>;

{--  Number of orders in a substate over time. 

  > Does "substate" relate to the primary/secondary state numbers
  > that you described before?  E.g. is 302 a substate of 3?
  > So this query might be "match all orders in state 3 or its
  > substates over some period of time"?
  
  I think the desired output here is a graph showing how many
  orders are in a given state (or substate) over time.  The time axis could
  be in days, weeks, or months.
  
  As you say, a substate of 3 is any state starting with a 3.  I think more
  generally we should just think of a group of states.

--}
<Q3>
</Q3>;

{--  Number of transitions into a given state (5).

  Count the number of transitions from each state into a particular
  state.  A transition is a juxtaposition of two states in the event
  sequence.

--}

{--

  This query computes the transition matrix (Cartesian product) of
  each state to each other state.  It brings Galax to a screeching
  halt!  Yes, that is really 78 minutes!

  real	78m48.879s
  user	71m4.410s
  sys	0m6.110s
--}

{--
<Q4>{ 
  let $states := distinct-values(data($dibbler/dibbler/order/event/state))
  for $s1 in $states
  return 
    <transition> 
      <from>{ $s1 }</from>
      <total>{ count($dibbler/dibbler/order/event[state = $s1 ]) }</total>
      { for $s2 in $states
        return <to>{ 
          $s2,
          <count>{ 
            count(
              for $o1 in $dibbler/dibbler/order, 
                  $e1 at $p1 in $o1/event
              where $e1/state = $s1 and $o1/event[$p1 + 1]/state = $s2
              return $s1
            )
          }</count>
        }</to>
      }
   </transition> 
}</Q4>;

--}


{-- Fix a date, for each state, report number of orders, time in that
    state. --}

{--
  For each order, determine the "state" of the order on the given date, ie,
  the last state in the event sequence whose time stamp precedes the given
  date.  For each such state, report how many orders are in that state, and
  the length of time they have been in that state, ie, the difference
  between the time stamp associated with the state in the order and the
  selected date.
--}

<Q5>
{  }
</Q5>;

