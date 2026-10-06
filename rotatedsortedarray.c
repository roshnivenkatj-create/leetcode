int search(int* a, int n, int target) {
    int l=0,r=n-1;

    while(l<=r) {
        int m=(l+r)/2;

        if(a[m]==target) return m;

        if(a[l]<=a[m]) {
            if(a[l]<=target && target<a[m])
                r=m-1;
            else
                l=m+1;
        }
        else {
            if(a[m]<target && target<=a[r])
                l=m+1;
            else
                r=m-1;
        }
    }
    return -1;
}