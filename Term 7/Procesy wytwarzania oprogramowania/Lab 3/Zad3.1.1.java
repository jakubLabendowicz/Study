class InternetStorage {

  ArrayList items = new ArrayList<>();
  public final int STATUS_NEW = 0;
  public final int STATUS_SOLD = 1;

  public void addItemToStorage(Item item) {
    items.add(item);
  }

  public void removeItemFromStorage(Item item) {
    items.remove(item);
  }

  public void sellItemFromStorage(int storageIndex) {
    Item item = items.get(storageIndex);
    item.setStus(STATUS_SOLD);
  }
}

class Item {

  String name;
  int price;

  public Item(String name, int price) {
    self.price = price;
    self.name = name;
  }
}

class Client {

  String name;
  String phone;

  public Client(String name, String phone) {
    self.name = name;
    self.phone = phone;
  }

  public String setName(String name) {
    self.name = name;
  }

  public String setPhone(String phone) {
    self.phone = phone;
  }
}
