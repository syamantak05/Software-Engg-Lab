#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
  int id;
  string name;
  double price;
  int quantity;

  Product(int id, string name, double price, int quantity) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
  }
};

class ProductManager {
private:
  vector<Product> products;

public:
  void addProduct(Product product) {
    products.push_back(product);
  }

  void updateProduct(int id, Product updatedProduct) {
    for (int i = 0; i < products.size(); i++) {
      if (products[i].id == id) {
        products[i] = updatedProduct;
        return;
      }
    }
    cout << "Product with ID " << id << " not found." << endl;
  }

  Product* getProduct(int id) {
    for (Product& product : products) {
      if (product.id == id) {
        return &product;
      }
    }
    return nullptr;
  }

  void removeProduct(int id) {
    int index = -1;
    for (int i = 0; i < products.size(); i++) {
      if (products[i].id == id) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      cout << "Product with ID " << id << " not found." << endl;
      return;
    }

    products.erase(products.begin() + index);
  }

  bool purchaseProduct(int id, int quantity) {
    Product* product = getProduct(id);
    if (!product) {
      return false;
    }

    if (product->quantity < quantity) {
      cout << "Insufficient stock for " << product->name << endl;
      return false;
    }

    product->quantity -= quantity;
    cout << quantity << " units of " << product->name << " purchased successfully." << endl;
    return true;
  }

  vector<Product> getAllProducts() {
    return products;
  }
};

int main() {
  ProductManager manager;

  manager.addProduct(Product(1, "Shirt", 19.99, 10));
  manager.addProduct(Product(2, "Book", 12.50, 5));

  manager.purchaseProduct(1, 2);

  Product updatedProduct(2, "Book", 14.99, 3);
  manager.updateProduct(2, updatedProduct);

  vector<Product> allProducts = manager.getAllProducts();
  for (Product product : allProducts) {
    cout << "ID: " << product.id << ", Name: " << product.name << ", Price: " << product.price << ", Quantity: " << product.quantity << endl;
  }

  return 0;
}

