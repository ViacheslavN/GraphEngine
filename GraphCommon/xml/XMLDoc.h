#pragma once

#include "../GraphCommon.h"
#include "../../../CommonLib/str/convertToString.h"

namespace GraphEngine
{
	namespace GraphCommon
	{
		namespace xml
		{
			class CXMLDoc : public IXMLDoc
			{
			public:

				enum enXmlLoadingState
				{
					xlsParseTag,
					xlsParseName,
					xlsParseCloseName,
					xlsParseAttributes

				};

				CXMLDoc();
				~CXMLDoc();

				virtual void Open(const astr& fileName);
				virtual void Open(CommonLib::IReadStream* pStream);

				virtual void Save(const astr& fileName);
				virtual void Save(CommonLib::IWriteStream* pStream);

				virtual IXMLNodePtr	GetNodes() const;
				virtual void Clear();

			private:
				//praser
				bool get_char(CommonLib::IReadStream* pStream);
				bool get_token(CommonLib::IReadStream* pStream);
				bool skip_space(CommonLib::IReadStream* pStream);
				bool find_open_tag(CommonLib::IReadStream* pStream);
				bool get_string(CommonLib::IReadStream* pStream);

				bool is_empty_char();
				bool is_escape_symbol();

				void parseName(CommonLib::IReadStream* pStream, enXmlLoadingState& state);

			private:

				char  m_char;
				astr m_token;
				std::vector<char> m_vecText;
				uint32_t m_nCurrCol;
				uint32_t m_nCurrRow;
				IXMLNodePtr m_pRoot;		 
			};
		}
	}
}