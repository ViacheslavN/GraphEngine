#pragma once

#include "../GraphGeometry/BoundaryBox.h"


namespace GraphEngine
{
	namespace GraphDatabase
	{
		enum eDataTypes
		{
			dtUnknown = 0,
			dtNull,
			dtInteger8,
			dtInteger16,
			dtInteger32,
			dtInteger64,
			dtUInteger8,
			dtUInteger16,
			dtUInteger32,
			dtUInteger64,
			dtOid32,
			dtOid64,
			dtFloat,
			dtDouble,
			dtString,
			dtBlob,
			dtRaster,
			dtDate,
			dtGeometry,
			dtSerializedObject,
			dtAnnotation
		};
		 

		enum eSpatialRel
		{
			srlUndefined = 0,
			srlIntersects = 1,
			srlTouches = 2,
			srlOverlaps = 3,
			srlCrosses = 4,
			srlWithin = 5,
			srlContains = 6,
			srlRelation = 7
		};




		typedef std::shared_ptr<class IField> IFieldPtr;
		typedef std::shared_ptr<class IFields> IFieldsPtr;
		typedef std::shared_ptr<class IRow> IRowPtr;
		typedef std::shared_ptr<class ICursor> ICursorPtr;
		typedef std::shared_ptr<class IInsertCursor> IInsertCursorPtr;
		typedef std::shared_ptr<class IUpdateCursor> IUpdateCursorPtr;
		typedef std::shared_ptr<class IDeleteCursor> IDeleteCursorPtr;
		
		class IField 
		{
		public:
			IField() {}
			virtual ~IField() {}
			virtual const astr&			 GetName() const = 0;
			virtual void                 SetName(const astr& name) = 0;
			virtual  const astr&		 GetAliasName() const = 0;
			virtual void                 SetAliasName(const astr&  name) = 0;
			virtual bool                 GetIsEditable() const = 0;
			virtual void                 SetIsEditable(bool flag) = 0;
			virtual bool                 GetIsNullable() const = 0;
			virtual void                 SetIsNullable(bool flag) = 0;
			virtual bool                 GetIsRequired() const = 0;
			virtual void                 SetIsRequired(bool flag) = 0;
			virtual eDataTypes			 GetType() const = 0;
			virtual void                 SetType(eDataTypes type) = 0;
			virtual int                  GetLength() const = 0;
			virtual void                 SetLength(int length) = 0;
			virtual int                  GetPrecision() const = 0;
			virtual void                 SetPrecision(int precision) = 0;
			virtual int                  GetScale() const = 0;
			virtual void                 SetScale(int scale) = 0;
			virtual bool                 GetIsPrimaryKey() const = 0;
			virtual void                 SetIsPrimaryKey(bool flag) = 0;
			virtual IFieldPtr			 Clone() const = 0;
			virtual std::any			 GetDefaultValue() const = 0;
			virtual void				 SetIsDefault(const std::any& value) = 0;
		};

		class IFields 
		{
		public:
			IFields() {}
			virtual ~IFields() {}
			virtual int       GetFieldCount() const = 0;
			virtual void      SetFieldCount(int count) = 0;
			virtual IFieldPtr GetField(int index) const = 0;
			virtual IFieldPtr  GetField(const astr& name) const = 0;
			virtual void      SetField(int index, IFieldPtr field) = 0;
			virtual void      AddField(IFieldPtr field) = 0;
			virtual void      RemoveField(int index) = 0;
			virtual int       FindField(const astr& name) const = 0;
			virtual bool      FieldExists(const astr& name) const = 0;
			virtual void	  Clear() = 0;
			virtual IFieldsPtr		clone() const = 0;
		};


		class IRow  
		{
		public:
			IRow() {}
			virtual ~IRow() {}
 
			virtual IFieldsPtr             GetFields() const = 0;  
			virtual std::any			   GetValue(int index) const= 0;
			virtual void				   SetValue(int index, const std::any& value) = 0;
			virtual bool                   HasOID() const = 0;
			virtual int64_t                GetOID() const = 0;
			virtual void                   SetOID(int64_t id) = 0;
			virtual int64_t				   GetRowID() const = 0;
			virtual void				   SetRowID(int64_t RowID) = 0;

			virtual int16_t ReadInt16(int32_t col) const = 0;
			virtual uint16_t ReadUInt16(int32_t col) const = 0;
			virtual int32_t ReadInt32(int32_t col) const = 0;
			virtual uint32_t ReadUInt32(int32_t col) const = 0;
			virtual int64_t ReadInt64(int32_t col) const = 0;
			virtual uint64_t ReadUInt64(int32_t col) const = 0;
			virtual float ReadFloat(int32_t col) const = 0;
			virtual double ReadDouble(int32_t col) const = 0;
			virtual void ReadText(int32_t col, astr& text) const = 0;
			virtual astr ReadText(int32_t col) const = 0;
			virtual void ReadBlob(int col, byte_t **pBuf, int32_t& size) const = 0;

			virtual void BindInt16(int32_t col, int16_t val) = 0;
			virtual void BindUInt16(int32_t col, uint16_t val) = 0;
			virtual void BindInt32(int32_t col, int32_t val) = 0;
			virtual void BindUInt32(int32_t col, uint32_t val) = 0;
			virtual void BindInt64(int32_t col, int64_t val) = 0;
			virtual void BindUInt64(int32_t col, uint64_t val) = 0;
			virtual void BindFloat(int32_t col, float val) = 0;
			virtual void BindDouble(int32_t col, double val) = 0;
			virtual void BindText(int32_t col, const astr& text, bool copy) = 0;
			virtual void BindBlob(int32_t col, const byte_t *pBuf, int32_t size, bool copy) = 0;
		};

		class ICursor  
		{
		public:
			ICursor() {}
			virtual ~ICursor() {}
			virtual IFieldsPtr   GetFields() const = 0;
			virtual bool NextRow(IRowPtr& row) = 0;
		};

		class  IInsertCursor 
		{
		public:
			IInsertCursor() {}
			virtual ~IInsertCursor() {}
			virtual IFieldsPtr   GetSourceFields() const = 0;
			virtual int64_t InsertRow(IRowPtr pRow) = 0;
		};

		class  IUpdateCursor : public ICursor
		{
		public:
			IUpdateCursor() {}
			virtual ~IUpdateCursor() {}
			virtual void UpdateRow(IRowPtr  pRow) = 0;
		};

		class IDeleteCursor 
		{
		public:
			IDeleteCursor() {}
			virtual ~IDeleteCursor() {}
			virtual void DeleteRow(int64_t oid) = 0;
		};

		class IQueryFilter  
		{
		public:
			IQueryFilter() {}
			virtual ~IQueryFilter() {}
			virtual IFieldsPtr							GetFieldSet() const = 0;
			virtual void                                SetFieldSet(IFieldsPtr fieldSet) = 0;
			virtual const astr&							GetWhereClause() const = 0;
			virtual void								SetWhereClause(const astr& where) = 0;
		};

		class ISpatialFilter : public IQueryFilter
		{
		public:
			ISpatialFilter(){}
			virtual ~ISpatialFilter(){}
			virtual GraphGeometry::BoundaryBox	 GetBB() const = 0;
			virtual void						 SetBB(const GraphGeometry::BoundaryBox& bbox) = 0;
			virtual double						 GetPrecision() const = 0;
			virtual void						 SetPrecision(double precision) = 0;
			virtual eSpatialRel					 GetSpatialRel() const = 0;
			virtual void						 SetSpatialRel(eSpatialRel rel) = 0;
		};

	}
}