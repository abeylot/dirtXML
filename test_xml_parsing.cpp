#include "dirtXML.hpp"
//sample of program using xml this parsing header

struct SampleXmlVisitor
{
    SampleXmlVisitor()
    {
    }

   virtual  ~SampleXmlVisitor()
    {
    }

    void log(uint64_t done)
    {
        std::cerr << " done " << (done >> UINT64_C(20)) << "Mio\n" << std::flush;
    }

    void stringNode(const std::vector<dirtXML::SeqBalise*>& tagStack, std::string& s)
    {
       std::cout << "tag contains string : [" << s << "]\n";
	}

    void xmlDescriptor(std::string& s)
    {
       std::cout << "xml infos : [" << s << "]\n";
	}

    void startTag(const std::vector<dirtXML::SeqBalise*>& tagStack, dirtXML::SeqBalise* b)
    {
		std::string path;
        for (int i = 0; i < tagStack.size(); i++)
		{
				path  += tagStack[i]->baliseName;
				path  += "->";
		}
        std::cout << "starting tag : " <<  path << b->baliseName << "\n";
        for (auto attribute : b->keyValues)
        {
            std::cout << "attribute : " << attribute.first << " value : " << attribute.second << "\n";
        }
    }

    void endTag(const std::vector<dirtXML::SeqBalise*>& tagStack, dirtXML::SeqBalise* b)
    {
        std::cout << "ending tag : " <<  b->baliseName << "\n";
    }

};

static void testXmlParsing()
{
   SampleXmlVisitor v;
   std::string s =         "<?xml version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"?>"
                           "<level1>"
                           "    my string 1 "
                           "    <level2 attr1=\"val1\" attr2=\"val2\"/>"
                           "    <![CDATA[<my cdata "
                           "    string>]]>"
                           "</level1>";

   std::stringstream my_stream(s);
   dirtXML::XmlFileParser<SampleXmlVisitor>::parseXmlIstream(my_stream, v);
}

 
int main()
{
    testXmlParsing();
}
