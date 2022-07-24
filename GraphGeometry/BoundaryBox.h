#pragma once
namespace GraphEngine
{
	namespace GraphGeometry
	{
		enum BboxType
		{
			bbox_type_invalid = 0xFFFFFFFF,
			bbox_type_null = 0,
			bbox_type_infinite = 1,
			bbox_type_normal = 2
		};

		enum BboxModifiers
		{
			bbox_has_zs = 0x80000000,
			bbox_has_ms = 0x40000000,
			bbox_basic_type_mask = 0x000000FF,
			bbox_modifier_mask = 0xFF000000
		};

		struct BoundaryBox
		{
			BboxType type;
			double xMin;
			double xMax;
			double yMin;
			double yMax;
			double zMin;
			double zMax;
			double mMin;
			double mMax;

			BoundaryBox();
			BoundaryBox(const BoundaryBox& bbox);
			BoundaryBox& operator=(const BoundaryBox& bbox);
			bool    operator==(const BoundaryBox &bbox) const;
			bool    operator!=(const BoundaryBox &bbox) const;
			bool    operator<(const BoundaryBox &bbox) const;
			bool    DoesInclude(const BoundaryBox &bbox, bool useZ = false, bool useM = false) const;
			bool    Contains(const BoundaryBox &bbox, bool useZ = false, bool useM = false) const;
			bool    Intersects(const BoundaryBox &bbox, bool useZ = false, bool useM = false) const;
			BoundaryBox& Expand(const BoundaryBox &bbox);
		};
	}
}