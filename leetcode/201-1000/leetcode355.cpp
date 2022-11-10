#include <iostream>
#include <vector>
using namespace std;

class Tweet {
private:
    int tweetID, userID;

public:
    Tweet(int userID, int tweetID)
    {
        this->tweetID = tweetID;
        this->userID = userID;
    }

    int getTweetID()
    {
        return tweetID;
    }

    int getUserID()
    {
        return userID;
    }
};

class Twitter {
private:
    int friendMap[505][505];
    vector<Tweet> tweet;

public:
    Twitter()
    {
        for (int i = 0; i < 505; i++) {
            for (int j = 0; j < 505; j++) {
                friendMap[i][j] = 0;
            }
        }
        tweet.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        Tweet t(userId, tweetId);
        tweet.push_back(t);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        for (int i = tweet.size() - 1; i >= 0; i--) {
            if (tweet[i].getUserID() == userId
                || friendMap[userId][tweet[i].getUserID()]) {
                res.push_back(tweet[i].getTweetID());
            }
            if (res.size() == 10)
                break;
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        friendMap[followerId][followeeId] = 1;
    }

    void unfollow(int followerId, int followeeId)
    {
        friendMap[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main(void) { return 0; }