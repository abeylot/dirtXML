# dirtXML
##
dirtXML is the dirtiest ( and also fast ) xml parsing c++ header only library ever.
It's a "SAX" like parsing header.
It was coded to parse openstreet map 80 gb compressed xml data file, with mainly speed requirement.
## documentation
see example cpp provided, you have to define a parsing object with all required methods
   then call :
   - dirtXML::XmlFileParser<my_visitor_type>::parseXmlIstream(my_stream, v);
   where my_stream is a c++ std::istream.
   or
   - dirtXML::XmlFileParser<my_visitor_type>::parseXmFile(my_file, v);
   where my_file is a standard c FILE*.
   
## WON'T DO
because we wish to be as fast as possible :
   - validity checks
   - error handling

