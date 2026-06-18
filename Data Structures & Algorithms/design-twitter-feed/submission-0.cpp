class Twitter {
    unordered_map<int , unordered_set<int>>userFollowing;
    unordered_map<int, vector<pair<int,int>>> userTweets;
    const int LIM = 10;
    int counter;
public:
    Twitter() {
        counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(counter++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> tweets;
        userFollowing[userId].insert(userId);
        for(auto& f: userFollowing[userId]){
            for(auto& t: userTweets[f]){
                tweets.emplace(t);
            }
        }

        vector<int>feed;
        feed.reserve(LIM);
        while(!tweets.empty() && feed.size() < LIM){
            feed.emplace_back(tweets.top().second);
            tweets.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }
};
