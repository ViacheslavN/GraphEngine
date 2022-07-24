#include "pch.h"
#include "XMLNode.h"
#include "XMLUtils.h"
#include "../../../CommonLib/str/str.h"

namespace GraphEngine
{
	namespace GraphCommon
	{
		namespace xml
		{
			CXMLNode::CXMLNode(IXMLNodePtr ptrParent, const astr& name) : m_name(name), m_ptrParent(ptrParent)
			{

			}

			CXMLNode::~CXMLNode()
			{

			}

			void CXMLNode::SetParent(IXMLNodePtr ptrParent)
			{
				m_ptrParent = ptrParent;
			}

			IXMLNodePtr	CXMLNode::CreateChildNode(const astr& name)
			{
				if(name.empty())
					throw CommonLib::CExcBase("XML::CreateChildNode: node name is empty");

				IXMLNodePtr ptrChild(new CXMLNode(shared_from_this(), name));

				m_Nodes.push_back(ptrChild);
				m_NodeByName.insert(std::make_pair(ptrChild->GetName(), (uint32_t)m_Nodes.size() - 1));

				return ptrChild;
			}

			uint32_t CXMLNode::CXMLNode::GetChildCnt() const
			{
				return (uint32_t)m_Nodes.size();
			}

			IXMLNodePtr	CXMLNode::GetChild(uint32_t nIndex) const
			{
				if (m_Nodes.size() > nIndex)
					return m_Nodes[nIndex];

				throw CommonLib::CExcBase("XML::GetChild out of range, nodes %1, index %2", m_Nodes.size(), nIndex);
			}

			bool CXMLNode::IsChildExists(const astr& name) const
			{
				auto it = m_NodeByName.find(name);
				return it != m_NodeByName.end();
			}

			IXMLNodePtr	CXMLNode::GetChild(const astr& name) const
			{
				TNodesByName::const_iterator it = m_NodeByName.find(name);
				if (it == m_NodeByName.end())
					throw CommonLib::CExcBase("XML::GetChild not found node with name %1", name);

				return GetChild(it->second);
			}

			std::vector<IXMLNodePtr> CXMLNode::GetChilds(const astr& name) const
			{

				std::vector<IXMLNodePtr> result;
				TNodesByName::_Paircc range_it = m_NodeByName.equal_range(name);
				for (auto it = range_it.first; it != range_it.second; ++it)
				{
					result.push_back(GetChild(it->second));
				}

				return result;
			}

			IXMLNodePtr	CXMLNode::GetParent() const
			{
				return m_ptrParent.lock();
			}

			const astr& CXMLNode::GetName() const
			{
				return m_name;
			}

			void CXMLNode::SetName(const astr& name)
			{
				m_name = name;
			}

			const astr& CXMLNode::GetText() const
			{
				return m_textUtf8;
			}

			void CXMLNode::SetText(const astr& text)
			{
				m_textUtf8 = text;
			}

			void  CXMLNode::SetText(const wstr& unicode)
			{
				m_textUtf8 = CommonLib::StringEncoding::str_w2utf8(unicode);
			}
 
			const astr& CXMLNode::GetCDATA() const
			{
				return m_caData;
			}

			void CXMLNode::SetCDATA(const  astr& cdata)
			{
				m_caData = cdata;
			}

			void CXMLNode::GetBlobCDATA(CommonLib::Data::TVecBuffer& data) const
			{
				CXMLUtils::String2Blob(m_caData, data);
			}

			void CXMLNode::SetBlobCDATA(const byte_t* data, size_t size)
			{
				CXMLUtils::Blob2String(data, size, m_caData);
			}

			void CXMLNode::AddPropertyInt16(const  astr& name, int16_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyInt16U(const astr& name, uint16_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyInt32(const astr& name, int32_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyInt32U(const astr& name, uint32_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyInt64(const astr& name, int64_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyIntU64(const astr& name, uint64_t value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyDouble(const astr& name, double value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyBool(const astr& name, bool value)
			{
				AddProperyT(name, value);
			}

			void CXMLNode::AddPropertyString(const astr& name, const astr& value)
			{
				TPropByName::iterator it = m_PropsByName.find(name);
				if (it == m_PropsByName.end())
				{
					m_Props.push_back(std::make_pair(name, value));
					m_PropsByName.insert(std::make_pair(name, (uint32_t) m_Props.size() - 1));
				}
				else
				{
					m_Props[it->second].second = value;
				}
			}

			void CXMLNode::AddPropertyWString(const astr& name, const wstr& value)
			{
				AddPropertyString(name, CommonLib::StringEncoding::str_w2utf8(value));
			}

			bool CXMLNode::IsPropertyExists(const astr& name) const
			{
				return m_PropsByName.find(name) != m_PropsByName.end();
			}

			const astr& CXMLNode::GetProperty(const astr& name) const
			{
				TPropByName::const_iterator c_it = m_PropsByName.find(name);
				if (c_it != m_PropsByName.end())
					return m_Props[c_it->second].second;

				throw CommonLib::CExcBase("XML::GetProperty not found property with name %1", name);

			}
			uint32_t CXMLNode::GetPropertyCnt() const
			{
				return (uint32_t)m_Props.size();
			}

			const astr&  CXMLNode::GetProperty(uint32_t nIndex) const
			{
				if (m_Props.size() > nIndex)
					return m_Props[nIndex].second;

				throw CommonLib::CExcBase("XML::GetProperty out of range, nodes %1, index %2", m_Props.size(), nIndex);
			}

			int16_t	CXMLNode::GetPropertyInt16(const astr& name, int16_t defValue) const
			{
				return GetProperyT<int16_t>(name, defValue);
			}

			uint16_t CXMLNode::GetPropertyInt16U(const astr& name, uint16_t defValue) const
			{
				return GetProperyT<uint16_t>(name, defValue);
			}
			int32_t	 CXMLNode::GetPropertyInt32(const astr& name, int32_t defValue) const
			{
				return GetProperyT<int32_t>(name, defValue);
			}

			uint32_t CXMLNode::GetPropertyInt32U(const astr& name, uint32_t defValue) const
			{
				return GetProperyT<uint32_t>(name, defValue);
			}

			int64_t	CXMLNode::GetPropertyInt64(const astr& name, int64_t defValue) const
			{
				return GetProperyT<int64_t>(name, defValue);
			}

			uint64_t CXMLNode::GetPropertyIntU64(const astr& name, uint64_t defValue) const
			{
				return GetProperyT<uint64_t>(name, defValue);
			}

			double  CXMLNode::GetPropertyDouble(const astr& name, double defValue) const
			{
				return GetProperyT<double>(name, defValue);
			}

			bool  CXMLNode::GetPropertyBool(const astr& name, bool defValue) const
			{
				return GetProperyT<bool>(name, defValue);
			}

			astr CXMLNode::GetPropertyString(const astr& name, const  astr& defValue) const
			{
				return GetProperyT<astr>(name, defValue);
			}

			wstr CXMLNode::GetPropertyWString(const astr& name, const  wstr& defValue) const
			{
				if (!IsPropertyExists(name))
					return defValue;

				wstr unicode;
				CommonLib::StringEncoding::str_utf82w(GetProperyT<astr>(name), unicode);

				return unicode;
			}



			int16_t	CXMLNode::GetPropertyInt16(const astr& name) const
			{
				return GetProperyT<int16_t>(name);
			}

			uint16_t CXMLNode::GetPropertyInt16U(const astr& name) const
			{
				return GetProperyT<uint16_t>(name);
			}

			int32_t	 CXMLNode::GetPropertyInt32(const astr& name) const
			{
				return GetProperyT<int32_t>(name);
			}

			uint32_t CXMLNode::GetPropertyInt32U(const astr& name) const
			{
				return GetProperyT<uint32_t>(name);
			}

			int64_t	CXMLNode::GetPropertyInt64(const astr& name) const
			{
				return GetProperyT<int64_t>(name);
			}

			uint64_t CXMLNode::GetPropertyIntU64(const astr& name) const
			{
				return GetProperyT<uint64_t>(name);
			}

			double  CXMLNode::GetPropertyDouble(const astr& name) const
			{
				return GetProperyT<double>(name);
			}

			bool CXMLNode::GetPropertyBool(const astr& name) const
			{
				return GetProperyT<bool>(name);
			}

			astr CXMLNode::GetPropertyString(const astr& name) const
			{
				return GetProperyT<astr>(name);
			}

			wstr CXMLNode::GetPropertyWString(const astr& name) const
			{
				wstr unicode;
				CommonLib::StringEncoding::str_utf82w(GetProperyT<astr>(name), unicode);

				return unicode;
			}
 

			void CXMLNode::Save(CommonLib::IWriteStream *pSteam)
			{
				try
				{
					astr sName;
					sName = CommonLib::str_format::AStrFormatSafeT("<%1", m_name);
					if (m_Props.empty() && m_textUtf8.empty() && m_caData.empty() && m_Nodes.empty())
					{
						sName += "/>\n";
						pSteam->Write(sName.c_str());
						return;
					}

					pSteam->Write(sName.c_str());
					if (!m_Props.empty())
					{
						astr sProps;
						for (size_t i = 0, sz = m_Props.size(); i < sz; ++i)
						{
							pSteam->Write(" ");
							pSteam->Write(m_Props[i].first.c_str());
							pSteam->Write("=\"");
							pSteam->Write(m_Props[i].second.c_str());
							pSteam->Write("\"");
						}

					}
					if (m_textUtf8.empty() && m_caData.empty() && m_Nodes.empty())
					{
						pSteam->Write("/>\n");
						return;
					}
					bool bClose = false;
					if (!m_Nodes.empty())
					{
						bClose = true;
						pSteam->Write(">\n");
						for (size_t i = 0, sz = m_Nodes.size(); i < sz; ++i)
						{
							((CXMLNode*)(m_Nodes[i].get()))->Save(pSteam);
						}
					}
					if (!m_textUtf8.empty())
					{
						if (!bClose)
						{
							pSteam->Write(">");
							bClose = true;
						}

						pSteam->Write(m_textUtf8.c_str());
					}

					if (!m_caData.empty())
					{
						if (!bClose)
						{
							pSteam->Write(">");
							bClose = true;
						}

						pSteam->Write("<![CDATA[ ");
						pSteam->Write(m_caData.c_str());
						pSteam->Write(" ]]>");
					}


					pSteam->Write("</");
					pSteam->Write(m_name.c_str());
					pSteam->Write(">\n");
				}
				catch (std::exception& exc)
				{
					CommonLib::CExcBase::RegenExc("Failed to save node: %1", m_name, exc);
				}
			
			}
		}
	}
}