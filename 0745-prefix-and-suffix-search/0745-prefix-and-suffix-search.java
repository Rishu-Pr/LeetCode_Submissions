class WordFilter {
    String[] words;
    public WordFilter(String[] words) {
        this.words = words;
    }
    
    public int f(String pref, String suff) {
        for(int i = words.length - 1; i >= 0; i--){
            String word = words[i];
            if (word.startsWith(pref) && word.endsWith(suff)) {
                return i;
            }
        }
        return -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */