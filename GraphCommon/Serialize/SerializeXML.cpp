#include "pch.h"
#include "SerializeXML.h"

namespace GraphEngine
{
	namespace GraphCommon
	{
		�SerializeObjXML::�SerializeObjXML(xml::IXMLNodePtr ptrNode) : m_ptrNode(ptrNode)
		{

		}

		�SerializeObjXML::~�SerializeObjXML()
		{

		}

		const astr& �SerializeObjXML::GetName() const
		{
			return m_ptrNode->GetName();
		}

		void  �SerializeObjXML::SetName(const astr& name)
		{
			m_ptrNode->SetName(name);
		}

		ISerializeObjPtr  �SerializeObjXML::CreateChildNode(const astr& name) const
		{
			return std::make_shared<�SerializeObjXML>(m_ptrNode->CreateChildNode(name));
		}

		uint32_t �SerializeObjXML::GetChildCnt() const
		{
			return m_ptrNode->GetChildCnt();
		}

		ISerializeObjPtr �SerializeObjXML::GetChild(uint32_t nIndex) const
		{
			return std::make_shared<�SerializeObjXML>(m_ptrNode->GetChild(nIndex));
		}

		ISerializeObjPtr �SerializeObjXML::GetChild(const astr& name) const
		{
			return std::make_shared<�SerializeObjXML>(m_ptrNode->GetChild(name));
		}

		std::vector<ISerializeObjPtr> �SerializeObjXML::GetChilds(const astr& name) const
		{
			std::vector<xml::IXMLNodePtr> nodes = m_ptrNode->GetChilds(name);
			std::vector<ISerializeObjPtr> ret;

			for (size_t i = 0, sz = nodes.size(); i < sz; ++i)
			{
				ret.push_back(std::make_shared<�SerializeObjXML>(nodes[i]));
			}

			return ret;
		}

		bool �SerializeObjXML::IsChildExists(const astr& name) const
		{
			return m_ptrNode->IsChildExists(name);
		}

		void �SerializeObjXML::GetBlob(CommonLib::Data::TVecBuffer& data) const
		{
			m_ptrNode->GetBlobCDATA(data);
		}

		void �SerializeObjXML::SetBlob(const byte_t* data, size_t size)
		{
			m_ptrNode->SetBlobCDATA(data, size);
		}

		void �SerializeObjXML::AddPropertyInt16(const  astr& name, int16_t value)
		{
			m_ptrNode->AddPropertyInt16(name, value);
		}

		void �SerializeObjXML::AddPropertyInt16U(const astr& name, uint16_t value)
		{
			m_ptrNode->AddPropertyInt16U(name, value);
		}

		void �SerializeObjXML::AddPropertyInt32(const astr& name, int32_t value)
		{
			m_ptrNode->AddPropertyInt32(name, value);
		}

		void �SerializeObjXML::AddPropertyInt32U(const astr& name, uint32_t value)
		{
			m_ptrNode->AddPropertyInt32U(name, value);
		}

		void �SerializeObjXML::AddPropertyInt64(const astr& name, int64_t value)
		{
			m_ptrNode->AddPropertyInt64(name, value);
		}

		void �SerializeObjXML::AddPropertyIntU64(const astr& name, uint64_t value)
		{
			m_ptrNode->AddPropertyIntU64(name, value);
		}

		void �SerializeObjXML::AddPropertyDouble(const astr& name, double value)
		{
			m_ptrNode->AddPropertyDouble(name, value);
		}

		void �SerializeObjXML::AddPropertyBool(const astr& name, bool value)
		{
			m_ptrNode->AddPropertyBool(name, value);
		}

		void �SerializeObjXML::AddPropertyString(const astr& name, const astr& valueUtf8)
		{
			m_ptrNode->AddPropertyString(name, valueUtf8);
		}

		void �SerializeObjXML::AddPropertyWString(const astr& name, const wstr& value)
		{
			m_ptrNode->AddPropertyWString(name, value);
		}


		bool �SerializeObjXML::IsPropertyExists(const astr& name) const
		{
			return m_ptrNode->IsPropertyExists(name);
		}

		const astr& �SerializeObjXML::GetProperty(const astr& name) const
		{
			return m_ptrNode->GetProperty(name);
		}

		uint32_t �SerializeObjXML::GetPropertyCnt() const
		{
			return m_ptrNode->GetPropertyCnt();
		}

		const astr&  �SerializeObjXML::GetProperty(uint32_t nIndex) const
		{
			return m_ptrNode->GetProperty(nIndex);
		}

		int16_t	�SerializeObjXML::GetPropertyInt16(const astr& name, int16_t defValue) const
		{
			return m_ptrNode->GetPropertyInt16(name, defValue);
		}

		uint16_t �SerializeObjXML::GetPropertyInt16U(const astr& name, uint16_t defValue) const
		{
			return m_ptrNode->GetPropertyInt16U(name, defValue);
		}

		int32_t	 �SerializeObjXML::GetPropertyInt32(const astr& name, int32_t defValue) const
		{
			return m_ptrNode->GetPropertyInt32(name, defValue);
		}

		uint32_t �SerializeObjXML::GetPropertyInt32U(const astr& name, uint32_t defValue) const
		{
			return m_ptrNode->GetPropertyInt32U(name, defValue);
		}

		int64_t	�SerializeObjXML::GetPropertyInt64(const astr& name, int64_t defValue) const
		{
			return m_ptrNode->GetPropertyInt64(name, defValue);
		}

		uint64_t �SerializeObjXML::GetPropertyIntU64(const astr& name, uint64_t defValue) const
		{
			return m_ptrNode->GetPropertyIntU64(name, defValue);
		}

		double  �SerializeObjXML::GetPropertyDouble(const astr& name, double defValue) const
		{
			return m_ptrNode->GetPropertyDouble(name, defValue);
		}

		bool  �SerializeObjXML::GetPropertyBool(const astr& name, bool defValue) const
		{
			return m_ptrNode->GetPropertyBool(name, defValue);
		}

		astr �SerializeObjXML::GetPropertyString(const astr& name, const  astr& defValueUtf8) const
		{
			return m_ptrNode->GetPropertyString(name, defValueUtf8);
		}

		wstr �SerializeObjXML::GetPropertyWString(const astr& name, const  wstr& defValue) const
		{
			return m_ptrNode->GetPropertyWString(name, defValue);
		}

		int16_t	�SerializeObjXML::GetPropertyInt16(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt16(name);
		}

		uint16_t �SerializeObjXML::GetPropertyInt16U(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt16U(name);
		}

		int32_t	 �SerializeObjXML::GetPropertyInt32(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt32(name);
		}

		uint32_t �SerializeObjXML::GetPropertyInt32U(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt32U(name);
		}

		int64_t	�SerializeObjXML::GetPropertyInt64(const astr& name) const
		{
			return m_ptrNode->GetPropertyInt64(name);
		}

		uint64_t �SerializeObjXML::GetPropertyIntU64(const astr& name) const
		{
			return m_ptrNode->GetPropertyIntU64(name);
		}

		double  �SerializeObjXML::GetPropertyDouble(const astr& name) const
		{
			return m_ptrNode->GetPropertyDouble(name);
		}

		bool  �SerializeObjXML::GetPropertyBool(const astr& name) const
		{
			return m_ptrNode->GetPropertyBool(name);
		}

		astr �SerializeObjXML::GetPropertyString(const astr& name) const
		{
			return m_ptrNode->GetPropertyString(name);
		}
	}
}