#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> insertsort(std::vector<int>& v)
{
    // start index at 1 since 0 is already sorted
    for (size_t i = 1; i < v.size(); i++) {
        int key = v.at(i);
        int j = i - 1; // second index to start at 0 for comparison
        // compare the current value to all the previously sorted ones
        while (j >= 0 && key > v.at(j)) {
            // shift the array
            v.at(j + 1) = v.at(j);
            j--; // comparing the key down the list right to left
        }
        // insert the key at the position where the left is smaller and sorted
        v[j + 1] = key;
    }
    return v;
}
void write_vector(std::vector<int> v)
{
    std::ofstream insert_out;
    // open the file and set to append the file
    insert_out.open("insert.out", std::ios_base::app);

    int size = static_cast<int>(v.size());
    for (int i = 0; i < size; i++) {
        insert_out << v.at(i) << " ";
    }
    insert_out << std::endl;
    insert_out.close();
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
        insertsort(nums);
        // write to file
        write_vector(nums);
        // clear the vector
        nums.clear();
    }
    return 0;
}
