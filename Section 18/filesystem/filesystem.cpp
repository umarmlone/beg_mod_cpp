#include <iostream>
#include <filesystem>
namespace fs = std::filesystem ;
void UsingPath() {
	fs::path selectedPath{R"(E:\Data\Material\C++\Assignments.docx)"} ;
	std::cout << selectedPath << std::endl;
	std::cout << selectedPath.string() << std::endl;

	selectedPath.remove_filename() ;
	selectedPath /= "newfile" ;
	
	if (selectedPath.has_root_name()) {
		std::cout << "root name\t = " << selectedPath.root_name().string() << std::endl;
	}
	if (selectedPath.has_root_path()) {
		std::cout << "root path\t = " << selectedPath.root_path().string() << std::endl;
	}
	if (selectedPath.has_root_directory()) {
		std::cout << "root directory\t = " << selectedPath.root_directory().string() << std::endl;
	}
	if (selectedPath.has_parent_path()) {
		std::cout << "parent path\t = " << selectedPath.parent_path().string() << std::endl;
	}
	if (selectedPath.has_relative_path()) {
		std::cout << "relative path\t = " << selectedPath.relative_path().string() << std::endl;
	}
	if (selectedPath.has_filename()) {
		std::cout << "filename\t = " << selectedPath.filename().string() << std::endl;
	}
	if (selectedPath.has_stem()) {
		std::cout << "stem part \t = " << selectedPath.stem().string() << std::endl;
	}
	if (selectedPath.has_extension()) {
		std::cout << "extension\t = " << selectedPath.extension().string() << std::endl;
	}
}

void TraversingDirectory(std::string_view file) {
	fs::path currentPath{file} ;
	std::vector<fs::directory_entry> dir_entries{} ;
	//fs::directory_iterator begin{currentPath} ;
	//fs::directory_iterator end{} ;
	//while(begin != end) {
	//	auto de = *begin++ ;
	//	std::cout << de.path().filename() << std::endl; 
	//}
	for(const auto & dir_entry : fs::directory_iterator{currentPath}) {
		dir_entries.push_back(dir_entry) ;
	}
	std::partition(dir_entries.begin(), dir_entries.end(), [](const fs::directory_entry & de) {
		return de.is_directory() ;
	}) ;
	for(const auto &dir_entry : dir_entries) {
		switch(const auto &p = dir_entry.path() ;/*dir_entry.status().type()*/ fs::status(p).type()) {
		case fs::file_type::directory:
			std::cout << "[DIR]\t" << p.string() << std::endl; 
			break ;
		case fs::file_type::regular:
			std::cout << '\t' << p.string() << '\t' << dir_entry.file_size() << std::endl; 
			break ;
		}
	}
}

void DirectoryOperations(std::string_view file) {
	fs::path currentPath{file} ;
	if(!fs::exists(currentPath)) {
		std::cout << "Path does not exist = >" << currentPath.string() << std::endl ;
		return ;
	}
	currentPath /= "NewDir" ;
	//if(!fs::create_directory(currentPath)) {
	//	std::cout << "Could not create a directory\n" ;
	//}else {
	//	std::cout << "Directory created successfully\n" ;
	//}
	//
	//if(!fs::remove(currentPath)) {
	//	std::cout << "Could not delete the directory\n" ;
	//}else {
	//	std::cout << "Directory removed successfully\n" ;
	//}
	try {
		std::cout << fs::current_path() << std::endl;
		std::cout << "Changing path\n";
		std::error_code ec{} ;
		fs::current_path(currentPath, ec);
		if(ec) {
			std::cout << "Error:" << ec.message() << std::endl;
			return ;
		}
		std::cout << fs::current_path() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "Exception:" << ex.what() << std::endl ;
	}
}

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
              << '\n';
}
void Permissions(std::string_view file) {
	fs::path file_to_modify{file} ;
	if(!fs::exists(file_to_modify)) {
		std::cout << "Path does not exist = >" << file_to_modify.string() << std::endl ;
		return ;
	}
	auto perm = fs::status(file_to_modify).permissions() ;
	demo_perms(perm) ;
	std::cout << "Changing permissions\n" ;
	fs::permissions(file_to_modify,fs::perms::owner_write, fs::perm_options::add) ;
	perm = fs::status(file_to_modify).permissions() ;
	demo_perms(perm) ;
}
int main() {
	//DirectoryOperations(R"(E:\Data)") ;
	//TraversingDirectory(R"(E:\Data)") ;
	Permissions(R"(E:\Data\Launcher.cs)") ;
}

