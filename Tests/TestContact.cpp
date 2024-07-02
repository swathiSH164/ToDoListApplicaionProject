#include "TestContact.h"

TestContact::TestContact()
{
    qDebug()<<"test contact constructor called";
}

TestContact::~TestContact()
{
   qDebug()<<"test contact destructor called";
}

void TestContact::SetUp()
{
  task= new Task();
}

void TestContact::TearDown() {
delete  task;
}
TEST_F(TestContact, Add) {


    int result=task->add(10,10);
    ASSERT_EQ(result,20);
}

// TEST_F(TestContact, AddvalidgroupContactTest) {
//     qDebug()<<"first fun1";
//     bool result=contactModel->Addcontact("ananya","8846664666","ananyag@gmail.com","","qrc:/images/girl (1)-modified.png");
//     ASSERT_TRUE(result);
// }

// TEST_F(TestContact, addSpacegroupmailid)
// {
//    qDebug()<<"first fun2";
//     bool result=contactModel->Addcontact("anu","8846566332","","","qrc:/images/profile_new1 (1)-modified (1).png");
//     ASSERT_TRUE(result);
// }

// TEST_F(TestContact, addInvalidPhnoContactTest) {
//     qDebug()<<"first fun4";
//     bool result=contactModel->Addcontact("","8846745766","","","qrc:/images/girl (1)-modified.png");
//     ASSERT_FALSE(result);
// }
// TEST_F(TestContact, addInvalidPhnoContactTest1) {
//     qDebug()<<"first fun5";

//     bool result=contactModel->Addcontact("ammu","8846","","","qrc:/images/girl (1)-modified.png");
//     qDebug()<<"inside 5 condition"<<result;
//     ASSERT_FALSE(result);
// }
// TEST_F(TestContact, addInvalidPhnoContactTest2) {
//     qDebug()<<"first fun6";

//     bool result=contactModel->Addcontact("ammu","884677585858888","","","qrc:/images/girl (1)-modified.png");
//     qDebug()<<"inside 6 condition"<<result;
//     ASSERT_FALSE(result);
// }



