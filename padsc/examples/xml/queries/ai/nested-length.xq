let $eventSeqLens := fn:data(./padsns:PSource/elt/events/length)
return <eventSeq><min>{fn:min($eventSeqLens)}</min><max>{fn:max($eventSeqLens)}</max></eventSeq>