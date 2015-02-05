Ptypedef Pstring_ME(:"/([0-9]{2}):([0-9]{2}):([0-9]{2})([ ]*(am|AM|pm|PM))?([ \\t]+([+-][0-1][0-9]00))?/":) PPtime;

Ptypedef Pstring_ME(:"/([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})/":) PPip;

Ptypedef Pstring_ME(:"/([0-9A-Za-z_][A-Za-z0-9_\\-]*)@((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*))/":) PPemail;

Ptypedef Pstring_ME(:"/(([0-9a-fA-F]{2})(:|\\-)){5}([0-9a-fA-F]{2})/":) PPmac;

Ptypedef Pstring_ME(:"/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\/([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([0-2][0-9]{3})|([0-2][0-9]{3})\\/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\-([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\-((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([0-2][0-9]{3})|([0-2][0-9]{3})\\-((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\.([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\.((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([0-2][0-9]{3})|([0-2][0-9]{3})\\.((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday|Sun|Sunday|mon|tue|wed|thu|fri|sat|sun),?[ \\t]+)?(Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)[ \\t]+([1-9]|[1-2][0-9]|0[1-9]|3[0-1])(,[ \\t]+([0-2][0-9]{3}))?|((Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday|Sun|Sunday|mon|tue|wed|thu|fri|sat|sun),?[ \\t]+)?([1-9]|[1-2][0-9]|0[1-9]|3[0-1])[ \\t]+(Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)(,[ \\t]+([0-2][0-9]{3}))?/":) PPdate;

Ptypedef Pstring_ME(:"/\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?)*\\/?|([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/(([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/)*([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?|\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?(\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?)*\\\\?|([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\(([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\)*([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?/":) PPpath;

Ptypedef Pstring_ME(:"/(http|ftp|https):\\/\\/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*))(:([1-9][0-9]*))?\\/?[^ \\t\\n\\r\"()']*|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*)\\?[^ \\t\\n\\r\"()']*|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*)|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\?[^ \\t\\n\\r\"()']*/":) PPurl;

Ptypedef Pstring_ME(:"/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.([a-zA-Z]+)|([0-9A-Za-z_][A-Za-z0-9_\\-]*)+\\.(com|net|edu|org|gov|co|ac|mil|info|int)(\\.[a-zA-Z][a-zA-Z])?)/":) PPhostname1;

Ptypedef Pstring_ME(:"/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.([a-zA-Z]+)
                        |([0-9A-Za-z_][A-Za-z0-9_\\-]*)+\\.(com|net|edu|org|gov|co|ac|mil|info|int)(\\.[a-zA-Z][a-zA-Z])?)/":) PPhostname21;

Ptypedef Pstring_ME(:"/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([a-zA-Z]+)
                        |([0-9A-Za-z_][A-Za-z0-9_\\-]*)+\\.(com|net|edu|org|gov|co|ac|mil|info|int)(\\.[a-zA-Z][a-zA-Z])?)/":) PPhostname;

Ptypedef Pstring_ME(:"/\\<([a-zA-Z])+\\>/":) PPbXML;

Ptypedef Pstring_ME(:"/\\<\\/[^>]+\\>/":) PPeXML;

Ptypedef Pstring_ME(:"/[ \\t\\r\\n]+/":) PPwhite;

Ptypedef Pstring_ME(:"/[0-9]+/":) PPint;

Ptypedef Pstring_ME(:"/([A-Za-z][A-Za-z0-9_\\-]*)/":) PPstring;

Ptypedef Pstring_ME(:"/[^0-9A-Za-z \\t\\r\\n]/":) PPchar;

