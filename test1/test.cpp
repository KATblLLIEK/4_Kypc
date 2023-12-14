#include "pch.h"
#include "../DeTa/List.h"
#include <string>

TEST(ListPushBack, ListPushBackWorkTest) {
	List<int> lst1;
	List<std::string> lst2;
	lst1.push_back(101);
	lst2.push_back("qwe");
	EXPECT_EQ(lst1.GetSize(), 1);
	EXPECT_EQ(lst1.top(), 101);
	EXPECT_EQ(lst2.GetSize(), 1);
	EXPECT_EQ(lst2.top(), "qwe");
}

/*
* @brief класс для тестирования
*/
class ListTest: public testing::Test {
protected:
	List<int> lst1;
	List<std::string> lst2;
	void SetUp() override {
		lst1.push_back(0);
		lst1.push_back(1);
		lst1.push_back(2);

		lst2.push_back("qwe");
		lst2.push_back("rty");
	}
};

TEST_F(ListTest, PopFrontWorks) {
	lst1.pop_front();
	EXPECT_EQ(lst1.GetSize(), 2);
	EXPECT_EQ(lst1.top(), 1);
}

TEST_F(ListTest, OperatorWorksInt) {
	EXPECT_EQ(lst1.top(), lst1[0]);
	lst1.push_back(3);
	EXPECT_EQ(3, lst1[3]);
}

TEST_F(ListTest, OperatorWorksString) {
	EXPECT_EQ(lst2.top(), lst2[0]);
	lst2.push_back("iop");
	EXPECT_EQ("iop", lst2[2]);
}

TEST_F(ListTest, PopBackWorks) {
	lst1.pop_back();
	EXPECT_EQ(lst1.GetSize(), 2);
}

TEST_F(ListTest, PushFrontWorksInt) {
	lst1.push_front(-1);
	EXPECT_EQ(lst1.GetSize(), 4);
	EXPECT_EQ(lst1.top(), -1);
}

TEST_F(ListTest, PushFrontWorksString) {
	lst2.push_front("iop");
	EXPECT_EQ(lst2.GetSize(), 3);
	EXPECT_EQ(lst2.top(), "iop");
}

TEST_F(ListTest, ClearWorks) {
	lst1.clear();
	EXPECT_EQ(lst1.GetSize(), 0);
}

TEST_F(ListTest, InsertWorksInt) {
	lst1.insert(5, 1);
	EXPECT_EQ(lst1.GetSize(), 4);
	EXPECT_EQ(lst1[1], 5);
}

TEST_F(ListTest, InsertWorksString) {
	lst2.insert("---", 1);
	EXPECT_EQ(lst2.GetSize(), 3);
	EXPECT_EQ(lst2[1], "---");
}

TEST_F(ListTest, RemoveAtWorks) {
	lst1.removeAt(1);
	EXPECT_EQ(lst1.GetSize(), 2);
	EXPECT_EQ(lst1[1], 2);
}

TEST_F(ListTest, CopyConstructorAndOperatorWork) {
	List<int> lst3;
	EXPECT_NO_FATAL_FAILURE(lst3 = List<int>(lst1));
	EXPECT_EQ(lst3.top(), 0);
	lst3.clear();
	EXPECT_EQ(lst1.GetSize(), 3);
}

TEST_F(ListTest, MoveConstructorAndOperatorWork) {
	List<int> lst3;
	lst3 = std::move(lst1);
	EXPECT_EQ(lst3.top(), 0);
	lst3.clear();
	EXPECT_EQ(lst1.GetSize(), 0);
}