import schema "http://www.padsproj.org/pads-xml.xsd" at "/home/mff/pads/padsc/schemata/pads-xml.xsd";
import schema namespace accum = "http://www.padsproj.org/pads-accum.xsd" at "/home/mff/pads/padsc/schemata/pads-accum.xsd";

declare variable $input as document-node() external;
validate { $input }

