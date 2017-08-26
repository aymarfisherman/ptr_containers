#include <gtest_wrapper.h>

#include <memory>
#include <boost/shared_ptr.hpp>

#include <ptr_containers.h>
using namespace ptr_containers;

template <typename Type_> class FloatPtrContainerTest : public testing::Test {};
typedef testing::Types<
	ptr_list<std::shared_ptr, float>,
	ptr_list<boost::shared_ptr, float>,
	ptr_vector<std::shared_ptr, float>,
	ptr_vector<boost::shared_ptr, float>
> float_ptr_container_types;

TYPED_TEST_CASE(FloatPtrContainerTest, float_ptr_container_types);
TYPED_TEST(FloatPtrContainerTest, FloatPtrContainerTest) {
	typedef TypeParam::type_shared_ptr type_shared_ptr;
	TypeParam floatContainer;

	type_shared_ptr value0(new float(5.0f));
	floatContainer.add(value0);
	
	EXPECT_TRUE(floatContainer.contains(value0));
	EXPECT_TRUE(floatContainer.contains(value0.get()));

	type_shared_ptr value1(new float(5.0f));

	EXPECT_TRUE(!floatContainer.contains(value1));
	EXPECT_TRUE(!floatContainer.contains(value1.get()));
	
	floatContainer.add(value1);
	floatContainer.add(value0);
	floatContainer.add(value1);
	floatContainer.add(value0);

	EXPECT_TRUE(floatContainer.contains(value1));
	EXPECT_TRUE(floatContainer.contains(value1.get()));

	floatContainer.remove(value0.get());
	EXPECT_TRUE(!floatContainer.contains(value0));
	EXPECT_TRUE(!floatContainer.contains(value0.get()));

	floatContainer.remove(value1);
	EXPECT_TRUE(!floatContainer.contains(value1));
	EXPECT_TRUE(!floatContainer.contains(value1.get()));
}

template <typename Type_> class FloatPtrUnorderedMapTest : public testing::Test {};
typedef testing::Types<
	ptr_unordered_map<std::shared_ptr, int, float>,
	ptr_unordered_map<boost::shared_ptr, int, float>
> float_ptr_unordered_map_types;

TYPED_TEST_CASE(FloatPtrUnorderedMapTest, float_ptr_unordered_map_types);
TYPED_TEST(FloatPtrUnorderedMapTest, FloatPtrUnorderedMapTest) {
	typedef TypeParam::type_shared_ptr type_shared_ptr;
	TypeParam floatUnorederedMap;

	type_shared_ptr value0(new float(5.0f));
	floatUnorederedMap[0] = value0;

	EXPECT_TRUE(floatUnorederedMap.contains(0));
	EXPECT_TRUE(!floatUnorederedMap.contains(1));

	EXPECT_TRUE(floatUnorederedMap.contains(value0));
	EXPECT_TRUE(floatUnorederedMap.contains(value0.get()));

	type_shared_ptr value1(new float(5.0f));

	EXPECT_TRUE(!floatUnorederedMap.contains(value1));
	EXPECT_TRUE(!floatUnorederedMap.contains(value1.get()));

	floatUnorederedMap[1] = value1;
	floatUnorederedMap[2] = value0;
	floatUnorederedMap[3] = value1;
	floatUnorederedMap[4] = value0;

	EXPECT_TRUE(floatUnorederedMap.contains(value1));
	EXPECT_TRUE(floatUnorederedMap.contains(value1.get()));

	floatUnorederedMap.remove(value0.get());
	EXPECT_TRUE(!floatUnorederedMap.contains(value0));
	EXPECT_TRUE(!floatUnorederedMap.contains(value0.get()));

	floatUnorederedMap.remove(value1);
	EXPECT_TRUE(!floatUnorederedMap.contains(value1));
	EXPECT_TRUE(!floatUnorederedMap.contains(value1.get()));

	EXPECT_TRUE(!floatUnorederedMap.get(0));
}