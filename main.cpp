#include <iostream>
#include <vector>

void print_vector(std::vector<int> v)
{
    int size = static_cast<int>(v.size());
    for (int i = 0; i < size; i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> output;

    while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0 && right.size() > 0) {
            // compare the heads of the two lists
            if (left.front() >= right.front()) {
                // push back the smaller value
                output.push_back(left.front());
                // erase the value from the orignal vector
                left.erase(left.begin());
            }
            else {
                // push back the smaller value
                output.push_back(right.front());
                // erase the value from the original vector
                right.erase(right.begin());
            }

            // copy the rest of the vector if any
        }
        else if (left.size() > 0) {
            for (auto&& i : left) {
                output.push_back(i);
            }
            break;
        }
        else if (right.size() > 0) {
            for (auto&& i : right) {
                output.push_back(i);
            }
            break;
        }
    }
    return output;
}

std::vector<int> mergesort(std::vector<int> input)
{
    if (input.size() <= 1) {
        return input;
    }

    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> sorted;

    int middle = static_cast<int>(input.size() + 1) / 2;
    int input_size = static_cast<int>(input.size());

    // divide array
    for (int i = 0; i < middle; i++) {
        left.push_back(input.at(i));
    }
    for (int i = middle; i < input_size; i++) {
        right.push_back(input.at(i));
    }

    left = mergesort(left);
    right = mergesort(right);
    sorted = merge(left, right);

    return sorted;
}

int main()
{

    std::vector<int> v;
    v.push_back(38);
    v.push_back(27);
    v.push_back(43);
    v.push_back(3);
    v.push_back(9);
    v.push_back(82);
    v.push_back(10);
    print_vector(v);
    std::cout << std::endl;
    std::vector<int> v2 = mergesort(v);
    print_vector(v2);
    return 0;
}
