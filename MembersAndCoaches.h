#include "BaseInfo.h"
#ifndef MEMBERSANDCOACHES_H_INCLUDED
#define MEMBERSANDCOACHES_H_INCLUDED
class Member : public BaseInfo
{
private :
    string  Subscription ;
public :
    Member ();
    void ShowData();
    void SetData ();
    void  SetSubscription(string);
    string  GetSubscription();
    void SetId ();
};
class Coach: public BaseInfo
{
    public :
    void SetId ();

};

#endif
