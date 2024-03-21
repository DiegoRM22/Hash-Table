#ifndef NETWORK_CARD_H
#define NETWORK_CARD_H

#include <iostream>
#include <algorithm>
#include <ctype.h>

class NetworkCard {
 public:
  NetworkCard() : macAddress_("00:00:00:00:00:00"), brand_("Asus"), model_("C45"), numberOfPorts_(3), highSpeed_(true) {}
  NetworkCard(const std::string& macAddress, const std::string& brand = "Asus", const std::string& model = "C45", int numberOfPorts = 3, bool highSpeed = true) : 
              macAddress_(macAddress), brand_(brand), model_(model), numberOfPorts_(numberOfPorts), highSpeed_(highSpeed) {}
  long calculatesValue() const {
    // Eliminar los : de la MAC
    std::string mac = macAddress_;
    mac.erase(std::remove(mac.begin(), mac.end(), ':'), mac.end());
    std::string auxResult = "";
    for (int character = 0; character < mac.size(); character++) {
      // Si es una letra, aádir su codigo ascii
      if (isalpha(mac[character])) {
        int asciiCode = mac[character];
        auxResult += std::to_string(asciiCode);
      } else {
        // Si es un número, añadirlo
        auxResult += mac[character];
      }
    }
    return std::stol(auxResult);
  }
  bool operator==(const NetworkCard& networkCard) const { return calculatesValue() == networkCard.calculatesValue(); }

 private:
  std::string macAddress_;
  std::string brand_;
  std::string model_;
  int numberOfPorts_;
  bool highSpeed_;
};

std::ostream& operator<<(std::ostream& os, const NetworkCard& networkCard) {
  os << "MAC Address: " << networkCard.calculatesValue() << std::endl;
  os << "Brand: " << networkCard.calculatesValue() << std::endl;
  os << "Model: " << networkCard.calculatesValue() << std::endl;
  os << "Number of ports: " << networkCard.calculatesValue() << std::endl;
  os << "High speed: " << networkCard.calculatesValue() << std::endl;
  return os;
}

#endif