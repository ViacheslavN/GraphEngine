#include "pch.h"
#include "SerializeXML.h"

namespace GraphEngine
{
	namespace GraphCommon
	{
		ÑSerializeObjXML::ÑSerializeObjXML(xml::IXMLNodePtr ptrNode) : m_ptrNode(ptrNode)
		{

		}

		ÑSerializeObjXML::~ÑSerializeObjXML()
		{

		}

		const astr& ÑSerializeObjXML::GetName() const
		{
			return m_ptrNode->GetName();
		}

		void  ÑSerializeObjXML::SetName(const astr& name)
		{
			m_ptrNode->SetName(name);
		}

		ISerializeObjPtr  ÑSerializeObjXML::CreateChildNode(const astr& name) const
		{
			return std::make_shared<ÑSerializeObjXML>(m_ptrNode->CreateChildNode(name));
		}

		uint32_t ÑSerializeObjXML::GetChildCnt() const
		{
			return m_ptrNode->GetChildCnt();
		}

		ISerializeObjPtr ÑSerializeObjXML::GetChild(uint32_t nIndex) const
		{
			return std::make_shared<ÑSerializeObjXML>(m_ptrNode->GetChild(nIndex));
		}

		ISerializeObjPtr ÑSerializeObjXML::GetChild(const astr& name) const
		{
			return std::make_shared<ÑSerializeObjXML>(m_ptrNode->GetChild(name));
		}

		std::vector<ISerializeObjPtr> ÑSerializeObjXML::GetChilds(const astr& name) const
		{
			std::vector<xml::IXMLNodePtr> nodes = m_ptrNode->GetChilds(name);
			std::vector<ISerializeObjPtr> ret;

			for (size_t i = 0, sz = nodes.size(); i < sz; ++i)
			{
				ret.push_back(std::make_shared<ÑSerializeObjXML>(nodes[i]));
			}

			return ret;
		}

		bool ÑSerializeObjXML::IsChildExists(const astr& name) const
		{
			return m_ptrNode->IsChildExists(name);
		}

		void ÑSerializeObjXML::GetBlob(CommonLib::Data::TVecBuffer& data) const
		{
			m_ptrNode->GetBlobCDATA(data);
		}

		void ÑSerializeObjXML::SetBlob(const byte_t* data, size_t size)
		{
			m_ptrNode->SetBlobCDATA(data, size);
		}

		void ÑSerializeObjXML::AddPropertyInt16(const  astr& name, int16_t value)
		{
			m_ptrNode->AddPropertyInt16(name, value);
		}

		void ÑSerializeObjXML::AddPropertyInt16U(const astr& name, uint16_t value)
		{
			m_ptrNode->AddPropertyInt16U(name, value);
		}

		void ÑSerializeObjXML::AddPropertyInt32(const astr& name, int32_t value)
		{
			m_ptrNode->AddPropertyInt32(name, value);
		}

		void ÑSerializeObjXML::AddPropertyInt32U(const astr& name, uint32_t value)
		{
			m_ptrNode->AddPropertyInt32U(name, value);
		}

		void ÑSerializeObjXML::AddPropertyInt64(const astr& name, int64_t value)
		{
			m_ptrNode->AddPropertyInt64(name, value);
		}

		void ÑSerializeObjXML::AddPropertyIntU64(const astr& name, uint64_t value)
		{
			m_ptrNode->AddPropertyIntU64(name, value);
		}

		void ÑSerializeObjXML::AddPropertyDouble(const astr& name, double value)
		{
			m_ptrNode->AddPropertyDouble(name, value);
		}

		void ÑSerializeObjXML::AddPropertyBool(const astr& name, bool value)
		{
			m_ptrNode->AddPropertyBool(name, value);
		}

		void ÑSerializeObjXML::AddPropertyString(const astr& name, const astr& valueUtf8)
		{
			m_ptrNode->AddPropertyString(name, valueUtf8);
		}

		void ÑSerializeObjXML::AddPropertyWString(const astr& name, const wstr& value)
		{
			m_ptrNode->AddPropertyWString(name, value);
		}


		bool ÑSerializeObjXML::IsPropertyExists(const astr& name) const
		{
			return m_ptrNode->IsPropertyExists(name);
		}

		const astr& ÑSerializeObjXML::GetProperty(const astr& name) const
		{
			return m_ptrNode->GetProperty(name);
		}

		uint32_t ÑSerializeObjXML::GetPropertyCnt() const
		{
			return m_ptrNode->GetPropertyCnt();
		}

		const astr&  ÑSerializeObjXML::GetProperty(uint32_t nIndex) const
		{
			return m_ptrNode->GetProperty(nIndex);
		}

		int16_t	ÑSerializeObjXML::GetPropertyInt16(const astr& name, int16_t defValue) const
		{
			return m_ptrNode->GetPropertyInt16(name, defValue);
		}

		uint16_t ÑSerializeObjXML::GetPropertyInt16U(const astr& name, uint16_t defValue) const
		{
			return m_ptrNode->GetPropertyInt16U(name, defValue);
		}

		int32_t	 ÑSerializeObjXML::GetPropertyInt32(const astr& name, int32_t defValue) const
		{
			return m_ptrNode->GetPropertyInt32(name, defValue);
		}

		uint32_t ÑSerializeObjXML::GetPropertyInt32U(const astr& name, uint32_t defValue) const
		{
			return m_ptrNode->GetPropertyInt32U(name, defValue);
		}

		int64_t	ÑSerializeObjXML::GetPropertyInt64(const astr& name, int64_t defValue) const
		{
			return m_ptrNode->GetPropertyInt64(name, defValue);
		}

		uint64_t ÑSerializeObjXML::GetPropertyIntU64(const astr& name, uint64_t defValue) const
		{
			return m_ptrNode->GetPropertyIntU64(name, defValue);
		}

		double  ÑSerializeObjXML::GetPropertyDouble(const astr& name, double defValue) const
		{
			return m_ptrNode->GetPropertyDouble(name, defValue);
		}

		bool  ÑSerializeObjXML::GetPropertyBool(const astr& name, bool defValue) const
		{
			return m_ptrNode->GetPropertyBool(name, defValue);
		}

		astr ÑSerializeObjXML::GetPropertyString(const astr& name, const  astr& defValueUtf8) const
		{
			return m_ptrNode->GetPropertyString(name, defValueUtf8);
		}

		wstr ÑSerializeObjXML::GetPropertyWString(const astr& name, const  wstr& defValue) const
		{
			return m_ptrNode->GetPropertyWString(name, defValue);
		}

		int16_t	ÑSerializeObjXML::GetPropertyInt16(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt16(name);
		}

		uint16_t ÑSerializeObjXML::GetPropertyInt16U(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt16U(name);
		}

		int32_t	 ÑSerializeObjXML::GetPropertyInt32(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt32(name);
		}

		uint32_t ÑSerializeObjXML::GetPropertyInt32U(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt32U(name);
		}

		int64_t	ÑSerializeObjXML::GetPropertyInt64(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt64(name);
		}

		uint64_t ÑSerializeObjXML::GetPropertyIntU64(const astr& name) const
		{
			return m_ptrNode->GetPropertyIntU64(name);
		}

		double  ÑSerializeObjXML::GetPropertyDouble(const astr& name) const
		{
			return m_ptrNode->GetPropertyDouble(name);
		}

		bool  ÑSerializeObjXML::GetPropertyBool(const astr& name) const
		{
			return m_ptrNode->GetPropertyBool(name);
		}

		astr ÑSerializeObjXML::GetPropertyString(const astr& name) const
		{
			return m_ptrNode->GetPropertyString(name);
		}
	}
}