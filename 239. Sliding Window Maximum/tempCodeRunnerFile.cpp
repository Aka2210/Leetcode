    if(nums[i] > nums[dq.front()])
                    dq.push_front(i);
                else if(nums[i] >= nums[dq.back()])
                {
                    dq.pop_back();
                    dq.push_back(i);
                }
                else if(dq.size() < 3)
                    dq.push_back(i);  