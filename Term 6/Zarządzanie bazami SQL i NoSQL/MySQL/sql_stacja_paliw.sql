-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 21 Mar 2022, 20:55
-- Wersja serwera: 10.4.22-MariaDB
-- Wersja PHP: 8.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `stacja_paliw`
--
CREATE DATABASE IF NOT EXISTS `stacja_paliw` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `stacja_paliw`;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `ceny_towarow`
--

CREATE TABLE `ceny_towarow` (
  `idceny_towarow` int(11) NOT NULL,
  `cena` float NOT NULL,
  `stacja` int(11) NOT NULL,
  `towar` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `ceny_towarow`
--

INSERT INTO `ceny_towarow` (`idceny_towarow`, `cena`, `stacja`, `towar`) VALUES
(1, 6.5, 1, 2),
(2, 7.5, 1, 1),
(3, 5.9, 1, 3),
(4, 6.9, 1, 4),
(5, 6.3, 1, 5),
(6, 7, 1, 6),
(7, 6.4, 1, 7),
(8, 5.4, 1, 8),
(9, 5.4, 2, 1),
(10, 5.4, 2, 2),
(11, 5.4, 2, 3),
(12, 5.4, 2, 4),
(13, 5.4, 2, 5),
(14, 5.4, 2, 6),
(15, 5.4, 2, 7),
(16, 5.4, 2, 8),
(17, 6.2, 3, 1),
(18, 6.2, 3, 2),
(19, 6.2, 3, 3),
(20, 6.2, 3, 4),
(21, 6.2, 3, 5),
(22, 6.2, 3, 6),
(23, 6.2, 3, 7),
(24, 6.2, 3, 8),
(25, 5.7, 4, 1),
(26, 5.7, 4, 2),
(27, 5.7, 4, 3),
(28, 5.7, 4, 4),
(29, 5.7, 4, 5),
(30, 5.7, 4, 6),
(31, 5.7, 4, 7),
(32, 5.7, 4, 8),
(33, 6.1, 5, 1),
(34, 6.1, 5, 2),
(35, 6.1, 5, 3),
(36, 6.1, 5, 4),
(37, 6.1, 5, 5),
(38, 6.1, 5, 6),
(39, 6.1, 5, 7),
(40, 6.1, 5, 8);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `nieruchomosci`
--

CREATE TABLE `nieruchomosci` (
  `idnieruchomosci` int(11) NOT NULL,
  `wojewodztwo` varchar(255) DEFAULT NULL,
  `miasto` varchar(255) DEFAULT NULL,
  `ulica` varchar(255) DEFAULT NULL,
  `numer_budynku` varchar(5) DEFAULT NULL,
  `kod_pocztowy` varchar(6) DEFAULT NULL,
  `typ_nieruchomosci` int(11) NOT NULL,
  `panstwo` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `nieruchomosci`
--

INSERT INTO `nieruchomosci` (`idnieruchomosci`, `wojewodztwo`, `miasto`, `ulica`, `numer_budynku`, `kod_pocztowy`, `typ_nieruchomosci`, `panstwo`) VALUES
(1, 'Mazowieckie', 'Warszawa', 'Marszałkowska', '55', '00-123', 1, 1),
(2, 'Lubelskie', 'Lublin', 'Nadbystrzycka', '33', '12-123', 1, 1),
(3, 'Lubelskie', 'Lublin', 'Zana', '34', '12-163', 1, 1),
(4, 'Lubelskie', 'Lublin', 'Wojciechowska', '11', '12-343', 1, 1),
(5, 'Pomorskie', 'Gdańsk', 'Nowa', '12', '32-313', 1, 1),
(6, 'Pomorskie', 'Gdańsk', 'Nowa', '13', '32-313', 2, 1),
(7, 'Lubelskie', 'Lublin', 'Nowa', '13', '12-313', 2, 1),
(8, 'Lubelskie', 'Lublin', 'Głęboka', '13', '12-313', 2, 1),
(9, 'Lubelskie', 'Lublin', 'Jana Pawła', '13', '12-313', 2, 1),
(10, 'Mazowieckie', 'Garwolin', 'Polna', '13', '08-400', 2, 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `panstwa`
--

CREATE TABLE `panstwa` (
  `idpanstwa` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `panstwa`
--

INSERT INTO `panstwa` (`idpanstwa`, `nazwa`) VALUES
(3, 'Francja'),
(4, 'Hiszpania'),
(2, 'Niemcy'),
(1, 'Polska'),
(5, 'Włochy');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `pracowicy`
--

CREATE TABLE `pracowicy` (
  `idpracowicy` int(11) NOT NULL,
  `imie` varchar(255) DEFAULT NULL,
  `nazwisko` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `miejsce_zatrudnienia` int(11) NOT NULL,
  `stanowisko_pracownika` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `pracowicy`
--

INSERT INTO `pracowicy` (`idpracowicy`, `imie`, `nazwisko`, `email`, `miejsce_zatrudnienia`, `stanowisko_pracownika`) VALUES
(1, 'Jakub', 'Łabendowicz', 'jl@gmail.com', 1, 4),
(2, 'Marcin', 'Ludian', 'ml@gmail.com', 2, 4),
(3, 'Michał', 'Łatwiński', 'mł@gmail.com', 3, 4),
(4, 'Magda', 'Kowalska', 'mk@gmail.com', 4, 3),
(7, 'Adam', 'Małysz', 'am@gmail.com', 7, 5),
(8, 'Michał', 'Małysz', 'mm@gmail.com', 7, 2),
(9, 'Artur', 'Woda', 'aw@gmail.com', 7, 1),
(10, 'Weronika', 'Woda', 'ww@gmail.com', 8, 1),
(11, 'Natalia', 'Las', 'nl@gmail.com', 8, 1),
(12, 'Aleksandra', 'Las', 'al@gmail.com', 8, 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `stanowiska_pracownikow`
--

CREATE TABLE `stanowiska_pracownikow` (
  `idstanowiska_pracownikow` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `stanowiska_pracownikow`
--

INSERT INTO `stanowiska_pracownikow` (`idstanowiska_pracownikow`, `nazwa`) VALUES
(5, 'Kierowca'),
(1, 'Kierownik magazynu'),
(4, 'Kierownik stacji'),
(2, 'Pracownik magazynu'),
(3, 'Pracownik stacji');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `stany_magazynowe_towarow`
--

CREATE TABLE `stany_magazynowe_towarow` (
  `idstany_magazynowe_towarow` int(11) NOT NULL,
  `ilosc` float NOT NULL,
  `nieruchomosc` int(11) NOT NULL,
  `towar` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `stany_magazynowe_towarow`
--

INSERT INTO `stany_magazynowe_towarow` (`idstany_magazynowe_towarow`, `ilosc`, `nieruchomosc`, `towar`) VALUES
(1, 2000, 1, 1),
(2, 2000, 1, 2),
(3, 2000, 1, 3),
(4, 2000, 1, 4),
(5, 2000, 1, 5),
(6, 2000, 1, 6),
(7, 2000, 1, 7),
(8, 2000, 1, 8),
(9, 2000, 2, 1),
(10, 2000, 2, 2),
(11, 2000, 2, 3),
(12, 2000, 2, 4),
(13, 2000, 2, 5),
(14, 2000, 2, 6),
(15, 2000, 2, 7),
(16, 2000, 2, 8),
(17, 2000, 3, 1),
(18, 2000, 3, 2),
(19, 2000, 3, 3),
(20, 2000, 3, 4),
(21, 2000, 3, 5),
(22, 2000, 3, 6),
(23, 2000, 3, 7),
(24, 2000, 3, 8),
(25, 1000, 4, 1),
(26, 1000, 4, 2),
(27, 1000, 4, 3),
(28, 1000, 4, 4),
(29, 1000, 4, 5),
(30, 1000, 4, 6),
(31, 1000, 4, 7),
(32, 1000, 4, 8),
(33, 500, 5, 1),
(34, 500, 5, 2),
(35, 500, 5, 3),
(36, 500, 5, 4),
(37, 500, 5, 5),
(38, 500, 5, 6),
(39, 500, 5, 7),
(40, 500, 5, 8);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `statusy_zamowien`
--

CREATE TABLE `statusy_zamowien` (
  `idstatusy_zamowien` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `statusy_zamowien`
--

INSERT INTO `statusy_zamowien` (`idstatusy_zamowien`, `nazwa`) VALUES
(2, 'Dostarczone'),
(3, 'W przygotowywaniu'),
(4, 'W transporcie'),
(1, 'Zamówione');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `towary`
--

CREATE TABLE `towary` (
  `idtowary` int(11) NOT NULL,
  `nazwa` varchar(255) NOT NULL,
  `typ_towaru` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `towary`
--

INSERT INTO `towary` (`idtowary`, `nazwa`, `typ_towaru`) VALUES
(1, 'Diesel +', 1),
(2, 'Diesel ++', 1),
(3, 'Diesel #', 1),
(4, 'Super 95', 2),
(5, 'Standard 95', 2),
(6, 'Standard 98', 3),
(7, 'Super 98', 3),
(8, 'Super LPG', 4);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `towary_w_zamowieniach`
--

CREATE TABLE `towary_w_zamowieniach` (
  `idtowary_w_zamowieniach` int(11) NOT NULL,
  `zamowienie` int(11) NOT NULL,
  `towar` int(11) NOT NULL,
  `ilosc` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `towary_w_zamowieniach`
--

INSERT INTO `towary_w_zamowieniach` (`idtowary_w_zamowieniach`, `zamowienie`, `towar`, `ilosc`) VALUES
(1, 1, 1, 200),
(2, 1, 2, 300),
(3, 1, 3, 400),
(4, 1, 4, 500),
(5, 2, 1, 500),
(6, 2, 2, 500),
(7, 2, 4, 500),
(8, 2, 7, 500),
(9, 3, 7, 500),
(10, 3, 1, 200),
(11, 3, 3, 200),
(12, 4, 3, 200),
(13, 5, 6, 700);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `typy_nieruchomosci`
--

CREATE TABLE `typy_nieruchomosci` (
  `idtypy_nieruchomosci` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `typy_nieruchomosci`
--

INSERT INTO `typy_nieruchomosci` (`idtypy_nieruchomosci`, `nazwa`) VALUES
(2, 'Magazyn'),
(1, 'Stacja paliw');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `typy_towarow`
--

CREATE TABLE `typy_towarow` (
  `idtypy_towarow` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `typy_towarow`
--

INSERT INTO `typy_towarow` (`idtypy_towarow`, `nazwa`) VALUES
(2, 'Benzyna 95'),
(3, 'Benzyna 98'),
(1, 'Diesel'),
(4, 'LPG');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `zamowienia`
--

CREATE TABLE `zamowienia` (
  `idzamowienia` int(11) NOT NULL,
  `magazyn` int(11) NOT NULL,
  `stacja` int(11) NOT NULL,
  `wlasciciel_zamowienia` int(11) NOT NULL,
  `kierowca` int(11) NOT NULL,
  `magazynier` int(11) NOT NULL,
  `status_zamowienia` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `zamowienia`
--

INSERT INTO `zamowienia` (`idzamowienia`, `magazyn`, `stacja`, `wlasciciel_zamowienia`, `kierowca`, `magazynier`, `status_zamowienia`) VALUES
(1, 6, 1, 1, 7, 8, 1),
(2, 6, 1, 1, 7, 8, 3),
(3, 7, 2, 2, 7, 8, 1),
(4, 8, 3, 3, 7, 8, 2),
(5, 9, 4, 4, 7, 8, 3);

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `ceny_towarow`
--
ALTER TABLE `ceny_towarow`
  ADD PRIMARY KEY (`idceny_towarow`,`stacja`,`towar`),
  ADD UNIQUE KEY `idceny_towarow_UNIQUE` (`idceny_towarow`),
  ADD KEY `fk_ceny_towarow_nieruchomosci1_idx` (`stacja`),
  ADD KEY `fk_ceny_towarow_towary1_idx` (`towar`);

--
-- Indeksy dla tabeli `nieruchomosci`
--
ALTER TABLE `nieruchomosci`
  ADD PRIMARY KEY (`idnieruchomosci`,`typ_nieruchomosci`,`panstwo`),
  ADD UNIQUE KEY `idnieruchomosci_UNIQUE` (`idnieruchomosci`),
  ADD KEY `fk_nieruchomosci_typ_nieruchomosci1_idx` (`typ_nieruchomosci`),
  ADD KEY `fk_nieruchomosci_panstwa1_idx` (`panstwo`);

--
-- Indeksy dla tabeli `panstwa`
--
ALTER TABLE `panstwa`
  ADD PRIMARY KEY (`idpanstwa`),
  ADD UNIQUE KEY `idpanstwa_UNIQUE` (`idpanstwa`),
  ADD UNIQUE KEY `nazwa_UNIQUE` (`nazwa`);

--
-- Indeksy dla tabeli `pracowicy`
--
ALTER TABLE `pracowicy`
  ADD PRIMARY KEY (`idpracowicy`,`miejsce_zatrudnienia`,`stanowisko_pracownika`),
  ADD UNIQUE KEY `idpracowicy_UNIQUE` (`idpracowicy`),
  ADD UNIQUE KEY `email_UNIQUE` (`email`),
  ADD KEY `fk_pracowicy_nieruchomosci1_idx` (`miejsce_zatrudnienia`),
  ADD KEY `fk_pracowicy_stanowiska_pracownikow1_idx` (`stanowisko_pracownika`);

--
-- Indeksy dla tabeli `stanowiska_pracownikow`
--
ALTER TABLE `stanowiska_pracownikow`
  ADD PRIMARY KEY (`idstanowiska_pracownikow`),
  ADD UNIQUE KEY `idstanowiska_pracownikow_UNIQUE` (`idstanowiska_pracownikow`),
  ADD UNIQUE KEY `nazwa_UNIQUE` (`nazwa`);

--
-- Indeksy dla tabeli `stany_magazynowe_towarow`
--
ALTER TABLE `stany_magazynowe_towarow`
  ADD PRIMARY KEY (`idstany_magazynowe_towarow`,`nieruchomosc`,`towar`),
  ADD UNIQUE KEY `idstany_magazynowe_towarow_UNIQUE` (`idstany_magazynowe_towarow`),
  ADD KEY `fk_stany_magazynowe_towarow_nieruchomosci1_idx` (`nieruchomosc`),
  ADD KEY `fk_stany_magazynowe_towarow_towary1_idx` (`towar`);

--
-- Indeksy dla tabeli `statusy_zamowien`
--
ALTER TABLE `statusy_zamowien`
  ADD PRIMARY KEY (`idstatusy_zamowien`),
  ADD UNIQUE KEY `idstatusy_zamowien_UNIQUE` (`idstatusy_zamowien`),
  ADD UNIQUE KEY `nazwa_UNIQUE` (`nazwa`);

--
-- Indeksy dla tabeli `towary`
--
ALTER TABLE `towary`
  ADD PRIMARY KEY (`idtowary`,`typ_towaru`),
  ADD UNIQUE KEY `idtowary_UNIQUE` (`idtowary`),
  ADD KEY `fk_towary_typy_towarow1_idx` (`typ_towaru`);

--
-- Indeksy dla tabeli `towary_w_zamowieniach`
--
ALTER TABLE `towary_w_zamowieniach`
  ADD PRIMARY KEY (`idtowary_w_zamowieniach`,`zamowienie`,`towar`),
  ADD UNIQUE KEY `idtowary_w_zamowieniach_UNIQUE` (`idtowary_w_zamowieniach`),
  ADD KEY `fk_zamowienia_has_towary_towary1_idx` (`towar`),
  ADD KEY `fk_zamowienia_has_towary_zamowienia1_idx` (`zamowienie`);

--
-- Indeksy dla tabeli `typy_nieruchomosci`
--
ALTER TABLE `typy_nieruchomosci`
  ADD PRIMARY KEY (`idtypy_nieruchomosci`),
  ADD UNIQUE KEY `idtyp_nieruchomosci_UNIQUE` (`idtypy_nieruchomosci`),
  ADD UNIQUE KEY `nazwa_UNIQUE` (`nazwa`);

--
-- Indeksy dla tabeli `typy_towarow`
--
ALTER TABLE `typy_towarow`
  ADD PRIMARY KEY (`idtypy_towarow`),
  ADD UNIQUE KEY `idtypy_towarow_UNIQUE` (`idtypy_towarow`),
  ADD UNIQUE KEY `nazwa_UNIQUE` (`nazwa`);

--
-- Indeksy dla tabeli `zamowienia`
--
ALTER TABLE `zamowienia`
  ADD PRIMARY KEY (`idzamowienia`,`magazyn`,`stacja`,`wlasciciel_zamowienia`,`kierowca`,`magazynier`,`status_zamowienia`),
  ADD UNIQUE KEY `idzamowienia_UNIQUE` (`idzamowienia`),
  ADD KEY `fk_zamowienia_nieruchomosci1_idx` (`magazyn`),
  ADD KEY `fk_zamowienia_nieruchomosci2_idx` (`stacja`),
  ADD KEY `fk_zamowienia_pracowicy1_idx` (`wlasciciel_zamowienia`),
  ADD KEY `fk_zamowienia_pracowicy2_idx` (`kierowca`),
  ADD KEY `fk_zamowienia_pracowicy3_idx` (`magazynier`),
  ADD KEY `fk_zamowienia_status_zamowienia1_idx` (`status_zamowienia`);

--
-- AUTO_INCREMENT dla zrzuconych tabel
--

--
-- AUTO_INCREMENT dla tabeli `ceny_towarow`
--
ALTER TABLE `ceny_towarow`
  MODIFY `idceny_towarow` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- AUTO_INCREMENT dla tabeli `nieruchomosci`
--
ALTER TABLE `nieruchomosci`
  MODIFY `idnieruchomosci` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT dla tabeli `panstwa`
--
ALTER TABLE `panstwa`
  MODIFY `idpanstwa` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT dla tabeli `pracowicy`
--
ALTER TABLE `pracowicy`
  MODIFY `idpracowicy` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT dla tabeli `stanowiska_pracownikow`
--
ALTER TABLE `stanowiska_pracownikow`
  MODIFY `idstanowiska_pracownikow` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT dla tabeli `stany_magazynowe_towarow`
--
ALTER TABLE `stany_magazynowe_towarow`
  MODIFY `idstany_magazynowe_towarow` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- AUTO_INCREMENT dla tabeli `statusy_zamowien`
--
ALTER TABLE `statusy_zamowien`
  MODIFY `idstatusy_zamowien` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT dla tabeli `towary`
--
ALTER TABLE `towary`
  MODIFY `idtowary` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT dla tabeli `towary_w_zamowieniach`
--
ALTER TABLE `towary_w_zamowieniach`
  MODIFY `idtowary_w_zamowieniach` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT dla tabeli `typy_nieruchomosci`
--
ALTER TABLE `typy_nieruchomosci`
  MODIFY `idtypy_nieruchomosci` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT dla tabeli `typy_towarow`
--
ALTER TABLE `typy_towarow`
  MODIFY `idtypy_towarow` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT dla tabeli `zamowienia`
--
ALTER TABLE `zamowienia`
  MODIFY `idzamowienia` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `ceny_towarow`
--
ALTER TABLE `ceny_towarow`
  ADD CONSTRAINT `fk_ceny_towarow_nieruchomosci1` FOREIGN KEY (`stacja`) REFERENCES `nieruchomosci` (`idnieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_ceny_towarow_towary1` FOREIGN KEY (`towar`) REFERENCES `towary` (`idtowary`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `nieruchomosci`
--
ALTER TABLE `nieruchomosci`
  ADD CONSTRAINT `fk_nieruchomosci_panstwa1` FOREIGN KEY (`panstwo`) REFERENCES `panstwa` (`idpanstwa`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nieruchomosci_typ_nieruchomosci1` FOREIGN KEY (`typ_nieruchomosci`) REFERENCES `typy_nieruchomosci` (`idtypy_nieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `pracowicy`
--
ALTER TABLE `pracowicy`
  ADD CONSTRAINT `fk_pracowicy_nieruchomosci1` FOREIGN KEY (`miejsce_zatrudnienia`) REFERENCES `nieruchomosci` (`idnieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_pracowicy_stanowiska_pracownikow1` FOREIGN KEY (`stanowisko_pracownika`) REFERENCES `stanowiska_pracownikow` (`idstanowiska_pracownikow`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `stany_magazynowe_towarow`
--
ALTER TABLE `stany_magazynowe_towarow`
  ADD CONSTRAINT `fk_stany_magazynowe_towarow_nieruchomosci1` FOREIGN KEY (`nieruchomosc`) REFERENCES `nieruchomosci` (`idnieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_stany_magazynowe_towarow_towary1` FOREIGN KEY (`towar`) REFERENCES `towary` (`idtowary`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `towary`
--
ALTER TABLE `towary`
  ADD CONSTRAINT `fk_towary_typy_towarow1` FOREIGN KEY (`typ_towaru`) REFERENCES `typy_towarow` (`idtypy_towarow`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `towary_w_zamowieniach`
--
ALTER TABLE `towary_w_zamowieniach`
  ADD CONSTRAINT `fk_zamowienia_has_towary_towary1` FOREIGN KEY (`towar`) REFERENCES `towary` (`idtowary`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_has_towary_zamowienia1` FOREIGN KEY (`zamowienie`) REFERENCES `zamowienia` (`idzamowienia`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Ograniczenia dla tabeli `zamowienia`
--
ALTER TABLE `zamowienia`
  ADD CONSTRAINT `fk_zamowienia_nieruchomosci1` FOREIGN KEY (`magazyn`) REFERENCES `nieruchomosci` (`idnieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_nieruchomosci2` FOREIGN KEY (`stacja`) REFERENCES `nieruchomosci` (`idnieruchomosci`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_pracowicy1` FOREIGN KEY (`wlasciciel_zamowienia`) REFERENCES `pracowicy` (`idpracowicy`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_pracowicy2` FOREIGN KEY (`kierowca`) REFERENCES `pracowicy` (`idpracowicy`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_pracowicy3` FOREIGN KEY (`magazynier`) REFERENCES `pracowicy` (`idpracowicy`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_zamowienia_status_zamowienia1` FOREIGN KEY (`status_zamowienia`) REFERENCES `statusy_zamowien` (`idstatusy_zamowien`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
