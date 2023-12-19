#include <iostream>
#include <vector>
#include <algorithm>

class FileSystemObject {
public:
    FileSystemObject(const std::string& name) : name(name) {}

    virtual void display() const = 0;

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

class File : public FileSystemObject {
public:
    File(const std::string& name, int size) : FileSystemObject(name), size(size) {}

    void display() const override {
        std::cout << "Dosya: " << getName() << " (Boyut: " << size << " bayt)" << std::endl;

    }

private:
    int size;
};

class Folder : public FileSystemObject {
public:
    Folder(const std::string& name) : FileSystemObject(name) {}

    void addFile(const FileSystemObject& file) {
        files.push_back(&file);  // File veya Folder nesnesinin işaretçisini ekleyin
    }

    void display() const override {
        std::cout << "Klasör: " << getName() << std::endl;
        std::cout << "İçerik:" << std::endl;

        for (const auto& file : files) {
            file->display();  // İşaretçiyi kullanarak display fonksiyonunu çağırın
        }
    }

private:
    std::vector<const FileSystemObject*> files;  // İşaretçi vektörü
};

int main() {
    setlocale(LC_ALL, "Turkish");
    File file1("metinbelgesi.txt", 1024);
    File file2("resim.jpg", 2048);

    Folder folder1("Dosya A");
    folder1.addFile(file1);
    folder1.addFile(file2);

    File file3("program.exe", 4096);

    Folder folder2("Dosya  B");
    folder2.addFile(file3);
    folder2.addFile(folder1);

    std::cout << "Dosya Sistemi Yapısı:" << std::endl;

    folder2.display();

    return 0;
}
