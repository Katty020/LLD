class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator currentpage;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentpage=history.begin();
    }
    
    void visit(string url) {
        list<string> :: iterator it=currentpage;
        it++;
        history.erase(it,history.end());
        history.push_back(url);
        currentpage++;
    }
    
    string back(int steps) {
        while((currentpage!=history.begin()) && steps--){
            --currentpage;
            
        }
        return *currentpage;
    }
    
    string forward(int steps) {
       while((currentpage!=--history.end()) && steps--){
            ++currentpage;
            
        } 
        return *currentpage;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
