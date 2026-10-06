int maxArea(int* h, int n) {
    int l=0,r=n-1,max=0;

    while(l<r) {
        int area=(h[l]<h[r]?h[l]:h[r])*(r-l);

        if(area>max) max=area;

        if(h[l]<h[r])
            l++;
        else
            r--;
    }

    return max;
}