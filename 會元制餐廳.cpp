#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// 定義菜品結構
struct MenuItem {
    string name;
    double price;
    string category;
};

// 定義訂單結構
struct Order {
    vector<MenuItem> items;
    double total;
};

class Restaurant {
private:
    vector<MenuItem> menu;
    vector<Order> orders;
    
    // 產生HTML頁首
    void writeHTMLHeader(ofstream &file) {
        file << "<!DOCTYPE html>\n"
             << "<html lang=\"zh-TW\">\n"
             << "<head>\n"
             << "    <meta charset=\"UTF-8\">\n"
             << "    <title>會元制餐廳</title>\n"
             << "    <style>\n"
             << "        body { font-family: Arial, sans-serif; margin: 20px; }\n"
             << "        table { border-collapse: collapse; width: 100%; margin-bottom: 20px; }\n"
             << "        th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n"
             << "        th { background-color: #4CAF50; color: white; }\n"
             << "        .category { background-color: #f2f2f2; font-weight: bold; }\n"
             << "        .total { font-weight: bold; color: #4CAF50; }\n"
             << "    </style>\n"
             << "</head>\n"
             << "<body>\n"
             << "    <h1>會元制餐廳</h1>\n";
    }
    
    // 產生HTML頁尾
    void writeHTMLFooter(ofstream &file) {
        file << "</body>\n</html>";
    }

public:
    // 初始化菜單
    Restaurant() {
        // 主菜
        menu.push_back({"炒飯", 80.0, "主食"});
        menu.push_back({"炒麵", 80.0, "主食"});
        menu.push_back({"燒肉飯", 100.0, "主食"});
        
        // 小菜
        menu.push_back({"涼拌黃瓜", 40.0, "小菜"});
        menu.push_back({"炒青菜", 50.0, "小菜"});
        menu.push_back({"蒜蓉空心菜", 60.0, "小菜"});
        
        // 飲料
        menu.push_back({"紅茶", 20.0, "飲料"});
        menu.push_back({"綠茶", 20.0, "飲料"});
        menu.push_back({"可樂", 25.0, "飲料"});
    }

    // 產生菜單HTML
    void generateMenuHTML() {
        ofstream file("restaurant_menu.html");
        
        if (file.is_open()) {
            writeHTMLHeader(file);
            
            // 輸出菜單
            file << "<h2>菜單</h2>\n"
                 << "<table>\n"
                 << "    <tr><th>分類</th><th>品項</th><th>價格</th></tr>\n";

            string currentCategory = "";
            for (const auto &item : menu) {
                if (currentCategory != item.category) {
                    currentCategory = item.category;
                }
                file << "    <tr>\n"
                     << "        <td>" << item.category << "</td>\n"
                     << "        <td>" << item.name << "</td>\n"
                     << "        <td>NT$" << fixed << setprecision(0) << item.price << "</td>\n"
                     << "    </tr>\n";
            }
            
            file << "</table>\n";
            
            // 簡單的訂購表單
            file << "<h2>線上訂購</h2>\n"
                 << "<form action=\"#\" method=\"post\">\n"
                 << "    <select name=\"meal\">\n";
            
            for (const auto &item : menu) {
                file << "        <option value=\"" << item.name << "\">" 
                     << item.name << " - NT$" << fixed << setprecision(0) 
                     << item.price << "</option>\n";
            }
            
            file << "    </select>\n"
                 << "    <input type=\"number\" name=\"quantity\" min=\"1\" value=\"1\">\n"
                 << "    <button type=\"submit\">加入訂單</button>\n"
                 << "</form>\n";

            writeHTMLFooter(file);
            file.close();
            
            cout << "菜單HTML檔案已經產生完成：restaurant_menu.html" << endl;
        } else {
            cout << "無法建立HTML檔案！" << endl;
        }
    }

    // 新增訂單
    void addOrder(const Order& order) {
        orders.push_back(order);
    }
};

int main() {
    Restaurant restaurant;
    restaurant.generateMenuHTML();
    return 0;
}
