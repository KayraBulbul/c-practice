#include <iostream>
#include <map>

struct Client {
  std::string name;
  int balance;
};

class BankingApp {

private:
  std::map<std::string, Client> clients;

public:
  BankingApp() = default; // Constructor

  void addClient(Client client) { clients[client.name] = client; }

  void removeClient(const std::string name) { clients.erase(name); }

  int showClientBalance(std::string name) const {
    return clients.at(name).balance;
  }

  void deposit(const std::string name, int amount) {
    if (amount > 0) {
      clients.at(name).balance += amount;
    } else {
      std::cout << "Cannot deposit a negative amount" << std::endl;
    }
  }

  void withdraw(const std::string name, int amount) {
    if (clients[name].balance >= amount && amount > 0) {
      clients.at(name).balance -= amount;
    } else if (amount < 0) {
      std::cout << "Cannot withdraw a negative amount" << std::endl;
    } else {
      std::cout << "Insufficient funds" << std::endl;
    }
  }

  void printClients() const {
    for (const auto &[name, client] : clients) {
      std::cout << "**************************" << '\n';
      std::cout << "Client: " << name << '\n';
      std::cout << "Balance: " << client.balance << '\n';
      std::cout << "**************************" << std::endl;
    }
  }

  ~BankingApp() = default; // Destructor - Maps delete the contents when deleted
                           // so no need to iterate through unlike a linked list
};

int main() {
  BankingApp bankingApp;

  bankingApp.addClient(Client{"Kayra", 100000});
  bankingApp.addClient(Client{"John", 479});
  bankingApp.addClient(Client{"Jane", 83});
  bankingApp.addClient(Client{"Alice", 7289});

  std::cout << "Kayra's balance is: " << bankingApp.showClientBalance("Kayra")
            << std::endl;

  bankingApp.deposit("Kayra", 50);
  std::cout << "Kayra's balance is: " << bankingApp.showClientBalance("Kayra")
            << std::endl;

  bankingApp.withdraw("Jane", 100);

  bankingApp.printClients();
  bankingApp.removeClient("John");
  bankingApp.printClients();

  return 0;
}
