#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

    // recusively divide
    left = mergesort(left);
    right = mergesort(right);
    // merge sorted arrays
    sorted = merge(left, right);

    return sorted;
}


void write_vector(std::vector<int> v)
{
    std::ofstream merge_out;
    // open the file and set to append the file
    merge_out.open("merge.out", std::ios_base::app);

    int size = static_cast<int>(v.size());
    for (int i = 0; i < size; i++) {
        merge_out << v.at(i) << " ";
    }
    merge_out << std::endl;
    merge_out.close();
}


int main()
{
    std::string line;
    std::vector<int> nums;

    // open the data file
    std::ifstream data;
    data.open("data.txt");

    // get the line
    while (std::getline(data, line)) {
        // convert line into a input string stream
        std::istringstream iss(line);
        int num;
        // store the numbers in the vector
        while (iss >> num) {
            nums.push_back(num);
        }

        // sort
        nums = mergesort(nums);
        // write to file
        write_vector(nums);
        // clear the vector
        nums.clear();
    }
    return 0;
}

