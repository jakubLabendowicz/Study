# Aplikacja LEMP

## Autor: Rafał Maciąg GL:5

### 1. Uruchamianie aplikacji

Aplikacje nalezy zbudowac poleceniem 
```bash
sudo docker-compose up 
 docker-compose up -d 

```
wydanym w terminalu w folderze glownym aplikacji . 

### 2. Struktura kodow zrodlowych
Drzewo plikow i katalogow (polecenie tree uzyte w glownym katalogu aplikacji)
.
├── docker-compose.yml
├── A
│   └── dockerfile
├── L
│   └── dockerfile
├── M
│   └── dockerfile
├── P
│   └── dockerfile
├── README.md
└── tree.txt

4 directories, 7 files


Aplikacja uruchamiana jest za pomoca pliku docker-compose.yml. Zdefiniowane jest w nim uruchamianie i konfigurowanie mikrouslug. W celu sprawdzenia lub modyfikacji szczegolow konfiguracji, nalezy zapoznac sie z plikami .dockerfile umieszczonymi w folderach.