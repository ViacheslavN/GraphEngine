// TestXML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#ifdef _WIN32
#include "../../../CommonLib/CommonLib_lib.h"
#endif

#include "../../GraphCommon/GraphCommon.h"
#include "../../GraphCommon/xml/XMLDoc.h"
#include "../../../CommonLib/stream/MemoryStream.h"
#include "../../../CommonLib/str/str.h"




int main()
{
	try
	{
		GraphEngine::GraphCommon::xml::CXMLDoc xmlDoc;

		GraphEngine::GraphCommon::IXMLNodePtr nodesPtr = xmlDoc.GetNodes();
		GraphEngine::GraphCommon::IXMLNodePtr pBody = nodesPtr->CreateChildNode("Body");

		CommonLib::CWriteMemoryStream memStream;

		memStream.Write(int64_t(456));
		memStream.Write(int(457));
		memStream.Write("строка");
		memStream.Write(L"Юникоде");
 


		pBody->AddPropertyDouble("double", 1.34);
		pBody->AddPropertyBool("bool", true);
		GraphEngine::GraphCommon::IXMLNodePtr pChild0 = pBody->CreateChildNode("Child0");
		pChild0->SetBlobCDATA(memStream.Buffer(), memStream.Size());
		pChild0->AddPropertyInt16("int", 10);
		pChild0->AddPropertyWString("Text", L"ТекстUnicodeテーブル");
		GraphEngine::GraphCommon::IXMLNodePtr pChild1 = pBody->CreateChildNode("Child1");
		pBody->CreateChildNode("Child2");
		for (size_t i = 0; i < 10; ++i)
		{
			GraphEngine::GraphCommon::IXMLNodePtr pRow = pChild1->CreateChildNode("Row");
			pRow->SetText(L"Текст Row");
			pRow->AddPropertyInt16("id", i);
			pRow->AddPropertyInt32("td", i + 1);
			pRow->AddPropertyString("text", "row");
			for (size_t j = 0; j < 1; ++j)
			{
				GraphEngine::GraphCommon::IXMLNodePtr pCell = pRow->CreateChildNode("cell");

			 
				pCell->AddPropertyInt32U("ID", j);
				wstr stext = CommonLib::str_format::WStrFormatSafeT(L"Идентификатор=%1", j);
				pCell->SetText(stext);
			}
		}
		xmlDoc.Save("D:\\xml\\test.xml");

		GraphEngine::GraphCommon::xml::CXMLDoc xmlDoc2;
		xmlDoc2.Open("D:\\xml\\test.xml");
		xmlDoc2.Save("D:\\xml\\test2.xml");

	}
	catch (const std::exception& exc)
	{

		std::cout << "Test xml failed: " << "\n";

		astrvec msgChain = CommonLib::CExcBase::GetChainFromExc(exc);


		for (size_t i = 0, sz = msgChain.size(); i < sz; ++i)
		{
			if (i != 0)
				std::cout << "\r\n";

			std::cout << msgChain[i];
		}
	 
	}
}
 