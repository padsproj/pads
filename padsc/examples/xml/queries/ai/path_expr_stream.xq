declare namespace padsns = "file:ai.p";
declare variable $src external;
for $v in fn:doc($src)/padsns:PSource/elt/response/val return $v