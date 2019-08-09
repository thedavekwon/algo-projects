// two pointers
int trap(vector<int>& height) {
    int left = 0; int right = height.size()-1;
    int left_max = 0; int right_max = 0;
    int ret = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                ret = ret + left_max-height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                ret = ret + right_max-height[right];
            }
            right--;
        }
    }
    return ret;
}

// stack
int trap(vector<int>& height) {
    int ret = 0, current = 0;
    stack<int> remaining;
    
    while (current < height.size()) {
        while (!remaining.empty() && height[current] > height[remaining.top()]) {
            int top = remaining.top();
            remaining.pop();
            if (remaining.empty()) break;
            int distance = current - remaining.top() - 1;
            int bounded_height = min(height[current], height[remaining.top()]) - height[top];
            ret = ret + distance * bounded_height;
        }
        remaining.push(current++);
    }
    return ret;
}

// dp
int trap(vector<int>& height) {
    if (height.size() == 0) return 0;
    vector<int> left(height.size());
    vector<int> right(height.size());
    
    left[0] = height[0];
    for (int i = 1; i < left.size(); i++) {
        left[i] = max(left[i-1], height[i]);
    }
    
    right[right.size()-1] = height[height.size()-1];
    for (int i = right.size()-2; i >=0; i--) {
        right[i] = max(right[i+1], height[i]);
    }
    
    int ret = 0;
    for (int i = 1; i < height.size()-1; i++) {
        ret = ret + min(left[i], right[i]) - height[i];
    }
    return ret;
}