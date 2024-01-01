//Eda Alparslan 22102334 Section 3
#include "SocialMediaPlatform.h"
#include <iostream>
using namespace std;
SocialMediaPlatform::SocialMediaPlatform(){
    regularUsers =  new LinkedSortedList<regularUser>();
    contentCreators =  new LinkedSortedList<contentCreator>();
    contents = new LinkedSortedList<content>();
}

SocialMediaPlatform::~SocialMediaPlatform(){

};
 void  SocialMediaPlatform::addRegularUser( const int regularUserId, const string name ){
    if(regularUsers->getPosition(regularUser(name, regularUserId)) <= 0){
    regularUser newUser = regularUser(name,regularUserId);
    regularUsers->insertSorted(newUser);
    cout << "Added regular user " << regularUserId << "." << endl;}
    else cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId << "." << endl;
 }
 void SocialMediaPlatform::removeRegularUser(const int regularUserId){
        int position = regularUsers->getPosition(regularUser("",regularUserId));
        if (position <= 0) cout<< "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << endl;
        else{
            for(int i = 1; i < contentCreators->getLength()+1 ; i++){
                if(contentCreators->getEntry(i).getFollowers()->getPosition(regularUserId)> 0)
                  contentCreators->getEntry(contentCreators->getPosition(contentCreator(i, ""))).getFollowers()->removeSorted(regularUserId);

            }

            regularUsers->remove(position);
            cout << "Removed regular user " << regularUserId << "." << endl;
        }
}

void SocialMediaPlatform::showAllRegularUsers( ) const{
    cout << "Regular users in the social media platform:" << endl;
    if(regularUsers->getLength() == 0) cout << "None" << endl;
    else{
        for (int i = 1; i < regularUsers->getLength()+1;i++){
            regularUser current = regularUsers->getEntry(i);
            cout << current.getUserId() << ", " << current.getUserName() << endl;
        }
    }



}

 void SocialMediaPlatform::addContentCreator( const int contentCreatorId, const string name ){
     if(contentCreators->getPosition(contentCreator(contentCreatorId, name))<= 0){
        contentCreators->insertSorted(contentCreator(contentCreatorId, name));
        cout << "Added content creator " << contentCreatorId << "." << endl;
     }
     else cout << "Cannot add content creator. There is already a content creator with ID " << contentCreatorId << "." << endl;
 }

void SocialMediaPlatform::removeContentCreator( const int contentCreatorId ){
    if(contentCreators->getPosition(contentCreator(contentCreatorId, ""))> 0){
        contentCreators->removeSorted(contentCreator(contentCreatorId, ""));
        cout << "Removed content creator " << contentCreatorId << "." << endl;
    }
    else cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "." << endl;

}

void SocialMediaPlatform::showAllContentCreators( ) const{
    cout << "Content creators in the social media platform:" << endl;
    if(contentCreators->getLength()== 0 ) cout << "None" << endl;
    else{
        for (int i = 1; i < contentCreators->getLength()+ 1; i++){
            contentCreator current = contentCreators->getEntry(i);
            cout <<current.getCreatorId()<< ", "<< current.getCreatorName() << ", " << current.getFollowers()->getLength() << " follower(s), "  << current.getContents()->getLength() << " content(s)"  << endl;             ;

        }
    }
}





void SocialMediaPlatform::addContent( const int contentCreatorId, const int contentId, const string title ){
    if(contents->getPosition(content(contentCreatorId, contentId, title))<= 0 && contentCreators->getPosition(contentCreator(contentCreatorId, "")) > 0){
        contents->insertSorted(content(contentCreatorId, contentId, title));
        contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId, ""))).getContents()->insertSorted(contentId);
        cout << "Added content " << contentId << "." << endl;

    }
    else if (contents->getPosition(content(contentCreatorId, contentId, title)) > 0) cout << "Cannot add content. There is already a content with ID " << contentId << "." << endl;
    else cout << "Cannot add content. There is no content creator with ID " << contentCreatorId <<  "." << endl;

}

void SocialMediaPlatform::removeContent( const int contentCreatorId, const int contentId) {
    if(contents->getPosition(content(contentCreatorId, contentId, ""))> 0 && contentCreators->getPosition(contentCreator(contentCreatorId, "")) > 0){
        contents->removeSorted(content(contentCreatorId, contentId, ""));
        contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId, ""))).getContents()->removeSorted(contentId);
        cout << "Removed content " << contentId << "." << endl;
    }
    else if (contentCreators->getPosition(contentCreator(contentCreatorId, ""))<= 0) cout << "Cannot remove content. There is no content creator with ID " << contentCreatorId <<  "." << endl;
    else cout << "Cannot remove content. There is no content with ID " << contentId << " shared by content creator with ID " << contentCreatorId << "." << endl;

}

 void SocialMediaPlatform:: showContentsOf( const int contentCreatorId ) const{
     if(contentCreators->getPosition(contentCreator(contentCreatorId,"")) <= 0) cout << "Cannot show. There is no content creator with ID " << contentCreatorId <<  "." << endl;
    else{
    cout << "Contents of content creator with ID " << contentCreatorId << ":" <<endl;
    if(contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId,""))).getContents()->getLength() == 0)
        cout <<"None" << endl;
    else{
        contentCreator creator = contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId,"")));
        for(int i = 1; i < creator.getContents()->getLength() + 1; i++){
            cout << creator.getContents()->getEntry(i) << endl;
        }



    }}
 }


 void SocialMediaPlatform::followContentCreator( const int regularUserId, const int contentCreatorId ){
    if(regularUsers->getPosition(regularUser("", regularUserId)) > 0 && contentCreators->getPosition(contentCreator(contentCreatorId, "")) > 0){
        contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId, ""))).getFollowers()->insertSorted(regularUserId);
        cout << "Regular user with ID " <<regularUserId << " followed content creator with ID " << contentCreatorId <<  "." << endl;

    }
    else cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;

 }

 void SocialMediaPlatform::unfollowContentCreator( const int regularUserId, const int contentCreatorId){
    if (contentCreators->getPosition(contentCreator(contentCreatorId, "")) <= 0 || regularUsers->getPosition(regularUser("", regularUserId)) <= 0)
        cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;
    else if(contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId, ""))).getFollowers()->getPosition(regularUserId) > 0){
        contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId, ""))).getFollowers()->removeSorted(regularUserId);
        cout << "Regular user with ID " <<regularUserId << " unfollowed content creator with ID " << contentCreatorId <<  "." << endl;

    }
    else cout << "Cannot unfollow. The user is not following the content creator." << endl;
 }

 void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const{
    if(contentCreators->getPosition(contentCreator(contentCreatorId,"")) <= 0) cout << "Cannot show. There is no content creator with ID " << contentCreatorId <<  "." << endl;
    else{cout << "Regular users following content creator with ID " << contentCreatorId << ":" <<endl;
    if(contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId,""))).getFollowers()->getLength() == 0)
        cout <<"None" << endl;
    else{
        contentCreator creator = contentCreators->getEntry(contentCreators->getPosition(contentCreator(contentCreatorId,"")));
        for(int i = 1; i < creator.getFollowers()->getLength() + 1; i++){
            cout << creator.getFollowers()->getEntry(i) << endl;
        }



    }}

 }
