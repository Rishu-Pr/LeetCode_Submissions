int maximum69Number (int num) {
    int ans = num;
    int temp = num;
    int idx = 1;

    while(temp > 9){
        idx *= 10;
        temp /= 10;
    }

    temp = num;
    while(idx){
        if(temp / idx == 6){
            if(ans < num + (3 * idx))
                ans = num + (3 * idx);
        }
        temp %= idx;
        idx /= 10;
    }

    return ans;
}