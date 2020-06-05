#include <scan_dir.hpp>
#include <queue>
#include <boost/filesystem.hpp>

/**
 * scan_dir returns by callback every directory and file that is within the specified path.
 * If an error occurs, e.g. permission denied, the error callback is called.
 * 
 * @param path The directory that will be scanned.
 * @param dir_callback For each found directory the callback function is called.
 * @param file_callback For each found file the callback function is called.
 * @param error_callback Is called when an error has occurred.
 */
void scan_dir(const boost::filesystem::path &path,
              const dir_callback &dir_callback,
              const file_callback &file_callback,
              const error_callback &error_callback)
{
    namespace fs = boost::filesystem;

    std::queue<fs::path> dir;
    dir.push(path);

    while (dir.empty() == false)
    {
        auto curr = dir.front();

        try
        {
            for (const auto &entry : fs::directory_iterator(curr))
            {
                auto curr_path = entry.path();
                if (fs::is_directory(curr_path))
                {
                    dir.push(curr_path);
                    dir_callback(curr_path);
                }
                if (fs::is_regular_file(curr_path))
                {
                    file_callback(curr_path);
                }
            }
        }
        catch (boost::filesystem::filesystem_error &ex)
        {
            error_callback(curr, ex);
        }

        dir.pop();
    }
}