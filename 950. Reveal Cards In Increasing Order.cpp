class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());

        deque<int> dq;
        dq.push_back(deck[0]);

        for(int i = 1; i < deck.size(); i++){
            //add this card deck[i] to the deck (dq)
            //bring last to front
            dq.push_front(dq.back());
            dq.pop_back();
            
            //add a new card - smaller
            dq.push_front(deck[i]);
        }

        vector<int> ans;

        for(int i = 0; i < deck.size(); i++){
            ans.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};

/*
    //sort the deck in reverse order 
    //the logic is that we are trying to work backwards
    //each time a number is reveled it leaves the remaining sequence
    //into some other arrangment with sending next number to end
    //so we implement it in reverse when a number is to 
    //be added to deck the last comes to first
    //and because we want to reveal smallest at first
    //we add it at last
*/