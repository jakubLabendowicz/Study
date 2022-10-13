-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 16 Mar 2022, 15:03
-- Wersja serwera: 10.4.20-MariaDB
-- Wersja PHP: 8.0.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `sakila`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `actor`
--

CREATE TABLE `actor` (
  `actor_id` smallint(5) UNSIGNED NOT NULL,
  `first_name` varchar(45) NOT NULL,
  `last_name` varchar(45) NOT NULL,
  `last_update` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `actor`
--

INSERT INTO `actor` (`actor_id`, `first_name`, `last_name`, `last_update`) VALUES
(1, 'PENELOPE', 'GUINESS', '2006-02-15 03:34:33'),
(2, 'NICK', 'WAHLBERG', '2006-02-15 03:34:33'),
(3, 'ED', 'CHASE', '2006-02-15 03:34:33'),
(4, 'JENNIFER', 'DAVIS', '2006-02-15 03:34:33'),
(5, 'JOHNNY', 'LOLLOBRIGIDA', '2006-02-15 03:34:33'),
(6, 'BETTE', 'NICHOLSON', '2006-02-15 03:34:33'),
(7, 'GRACE', 'MOSTEL', '2006-02-15 03:34:33'),
(8, 'MATTHEW', 'JOHANSSON', '2006-02-15 03:34:33'),
(9, 'JOE', 'SWANK', '2006-02-15 03:34:33'),
(10, 'CHRISTIAN', 'GABLE', '2006-02-15 03:34:33'),
(11, 'ZERO', 'CAGE', '2006-02-15 03:34:33'),
(12, 'KARL', 'BERRY', '2006-02-15 03:34:33'),
(13, 'UMA', 'WOOD', '2006-02-15 03:34:33'),
(14, 'VIVIEN', 'BERGEN', '2006-02-15 03:34:33'),
(15, 'CUBA', 'OLIVIER', '2006-02-15 03:34:33'),
(16, 'FRED', 'COSTNER', '2006-02-15 03:34:33'),
(17, 'HELEN', 'VOIGHT', '2006-02-15 03:34:33'),
(18, 'DAN', 'TORN', '2006-02-15 03:34:33'),
(19, 'BOB', 'FAWCETT', '2006-02-15 03:34:33'),
(20, 'LUCILLE', 'TRACY', '2006-02-15 03:34:33'),
(21, 'KIRSTEN', 'PALTROW', '2006-02-15 03:34:33'),
(22, 'ELVIS', 'MARX', '2006-02-15 03:34:33'),
(23, 'SANDRA', 'KILMER', '2006-02-15 03:34:33'),
(24, 'CAMERON', 'STREEP', '2006-02-15 03:34:33'),
(25, 'KEVIN', 'BLOOM', '2006-02-15 03:34:33'),
(26, 'RIP', 'CRAWFORD', '2006-02-15 03:34:33'),
(27, 'JULIA', 'MCQUEEN', '2006-02-15 03:34:33'),
(28, 'WOODY', 'HOFFMAN', '2006-02-15 03:34:33'),
(29, 'ALEC', 'WAYNE', '2006-02-15 03:34:33'),
(30, 'SANDRA', 'PECK', '2006-02-15 03:34:33'),
(31, 'SISSY', 'SOBIESKI', '2006-02-15 03:34:33'),
(32, 'TIM', 'HACKMAN', '2006-02-15 03:34:33'),
(33, 'MILLA', 'PECK', '2006-02-15 03:34:33'),
(34, 'AUDREY', 'OLIVIER', '2006-02-15 03:34:33'),
(35, 'JUDY', 'DEAN', '2006-02-15 03:34:33'),
(36, 'BURT', 'DUKAKIS', '2006-02-15 03:34:33'),
(37, 'VAL', 'BOLGER', '2006-02-15 03:34:33'),
(38, 'TOM', 'MCKELLEN', '2006-02-15 03:34:33'),
(39, 'GOLDIE', 'BRODY', '2006-02-15 03:34:33'),
(40, 'JOHNNY', 'CAGE', '2006-02-15 03:34:33'),
(41, 'JODIE', 'DEGENERES', '2006-02-15 03:34:33'),
(42, 'TOM', 'MIRANDA', '2006-02-15 03:34:33'),
(43, 'KIRK', 'JOVOVICH', '2006-02-15 03:34:33'),
(44, 'NICK', 'STALLONE', '2006-02-15 03:34:33'),
(45, 'REESE', 'KILMER', '2006-02-15 03:34:33'),
(46, 'PARKER', 'GOLDBERG', '2006-02-15 03:34:33'),
(47, 'JULIA', 'BARRYMORE', '2006-02-15 03:34:33'),
(48, 'FRANCES', 'DAY-LEWIS', '2006-02-15 03:34:33'),
(49, 'ANNE', 'CRONYN', '2006-02-15 03:34:33'),
(50, 'NATALIE', 'HOPKINS', '2006-02-15 03:34:33'),
(51, 'GARY', 'PHOENIX', '2006-02-15 03:34:33'),
(52, 'CARMEN', 'HUNT', '2006-02-15 03:34:33'),
(53, 'MENA', 'TEMPLE', '2006-02-15 03:34:33'),
(54, 'PENELOPE', 'PINKETT', '2006-02-15 03:34:33'),
(55, 'FAY', 'KILMER', '2006-02-15 03:34:33'),
(56, 'DAN', 'HARRIS', '2006-02-15 03:34:33'),
(57, 'JUDE', 'CRUISE', '2006-02-15 03:34:33'),
(58, 'CHRISTIAN', 'AKROYD', '2006-02-15 03:34:33'),
(59, 'DUSTIN', 'TAUTOU', '2006-02-15 03:34:33'),
(60, 'HENRY', 'BERRY', '2006-02-15 03:34:33'),
(61, 'CHRISTIAN', 'NEESON', '2006-02-15 03:34:33'),
(62, 'JAYNE', 'NEESON', '2006-02-15 03:34:33'),
(63, 'CAMERON', 'WRAY', '2006-02-15 03:34:33'),
(64, 'RAY', 'JOHANSSON', '2006-02-15 03:34:33'),
(65, 'ANGELA', 'HUDSON', '2006-02-15 03:34:33'),
(66, 'MARY', 'TANDY', '2006-02-15 03:34:33'),
(67, 'JESSICA', 'BAILEY', '2006-02-15 03:34:33'),
(68, 'RIP', 'WINSLET', '2006-02-15 03:34:33'),
(69, 'KENNETH', 'PALTROW', '2006-02-15 03:34:33'),
(70, 'MICHELLE', 'MCCONAUGHEY', '2006-02-15 03:34:33'),
(71, 'CHRIS', 'GRANT', '2022-03-16 13:57:34'),
(72, 'SEAN', 'WILLIAMS', '2006-02-15 03:34:33'),
(73, 'GARY', 'PENN', '2006-02-15 03:34:33'),
(74, 'MILLA', 'KEITEL', '2006-02-15 03:34:33'),
(75, 'BURT', 'POSEY', '2006-02-15 03:34:33'),
(76, 'ANGELINA', 'ASTAIRE', '2006-02-15 03:34:33'),
(77, 'CARY', 'MCCONAUGHEY', '2006-02-15 03:34:33'),
(78, 'GROUCHO', 'SINATRA', '2006-02-15 03:34:33'),
(79, 'MAE', 'HOFFMAN', '2006-02-15 03:34:33'),
(80, 'RALPH', 'CRUZ', '2006-02-15 03:34:33'),
(81, 'SCARLETT', 'DAMON', '2006-02-15 03:34:33'),
(82, 'WOODY', 'JOLIE', '2006-02-15 03:34:33'),
(83, 'BEN', 'WILLIS', '2006-02-15 03:34:33'),
(84, 'JAMES', 'PITT', '2006-02-15 03:34:33'),
(85, 'MINNIE', 'ZELLWEGER', '2006-02-15 03:34:33'),
(86, 'GREG', 'CHAPLIN', '2006-02-15 03:34:33'),
(87, 'SPENCER', 'PECK', '2006-02-15 03:34:33'),
(88, 'KENNETH', 'PESCI', '2006-02-15 03:34:33'),
(89, 'CHARLIZE', 'DENCH', '2006-02-15 03:34:33'),
(90, 'SEAN', 'GUINESS', '2006-02-15 03:34:33'),
(91, 'CHRISTOPHER', 'BERRY', '2006-02-15 03:34:33'),
(92, 'KIRSTEN', 'AKROYD', '2006-02-15 03:34:33'),
(93, 'ELLEN', 'PRESLEY', '2006-02-15 03:34:33'),
(94, 'KENNETH', 'TORN', '2006-02-15 03:34:33'),
(95, 'DARYL', 'WAHLBERG', '2006-02-15 03:34:33'),
(96, 'GENE', 'WILLIS', '2006-02-15 03:34:33'),
(97, 'MEG', 'HAWKE', '2006-02-15 03:34:33'),
(98, 'CHRIS', 'BRIDGES', '2006-02-15 03:34:33'),
(99, 'JIM', 'MOSTEL', '2006-02-15 03:34:33'),
(100, 'SPENCER', 'DEPP', '2006-02-15 03:34:33'),
(101, 'SUSAN', 'DAVIS', '2006-02-15 03:34:33'),
(102, 'WALTER', 'TORN', '2006-02-15 03:34:33'),
(103, 'MATTHEW', 'LEIGH', '2006-02-15 03:34:33'),
(104, 'PENELOPE', 'CRONYN', '2006-02-15 03:34:33'),
(105, 'SIDNEY', 'CROWE', '2006-02-15 03:34:33'),
(106, 'GROUCHO', 'DUNST', '2006-02-15 03:34:33'),
(107, 'GINA', 'DEGENERES', '2006-02-15 03:34:33'),
(108, 'WARREN', 'NOLTE', '2006-02-15 03:34:33'),
(109, 'SYLVESTER', 'DERN', '2006-02-15 03:34:33'),
(110, 'SUSAN', 'DAVIS', '2006-02-15 03:34:33'),
(111, 'CAMERON', 'ZELLWEGER', '2006-02-15 03:34:33'),
(112, 'RUSSELL', 'BACALL', '2006-02-15 03:34:33'),
(113, 'MORGAN', 'HOPKINS', '2006-02-15 03:34:33'),
(114, 'MORGAN', 'MCDORMAND', '2006-02-15 03:34:33'),
(115, 'HARRISON', 'BALE', '2006-02-15 03:34:33'),
(116, 'DAN', 'STREEP', '2006-02-15 03:34:33'),
(117, 'RENEE', 'TRACY', '2006-02-15 03:34:33'),
(118, 'CUBA', 'ALLEN', '2006-02-15 03:34:33'),
(119, 'WARREN', 'JACKMAN', '2006-02-15 03:34:33'),
(120, 'PENELOPE', 'MONROE', '2006-02-15 03:34:33'),
(121, 'LIZA', 'BERGMAN', '2006-02-15 03:34:33'),
(122, 'SALMA', 'NOLTE', '2006-02-15 03:34:33'),
(123, 'JULIANNE', 'DENCH', '2006-02-15 03:34:33'),
(124, 'SCARLETT', 'BENING', '2006-02-15 03:34:33'),
(125, 'ALBERT', 'NOLTE', '2006-02-15 03:34:33'),
(126, 'FRANCES', 'TOMEI', '2006-02-15 03:34:33'),
(127, 'KEVIN', 'GARLAND', '2006-02-15 03:34:33'),
(128, 'CATE', 'MCQUEEN', '2006-02-15 03:34:33'),
(129, 'DARYL', 'CRAWFORD', '2006-02-15 03:34:33'),
(130, 'GRETA', 'KEITEL', '2006-02-15 03:34:33'),
(131, 'JANE', 'JACKMAN', '2006-02-15 03:34:33'),
(132, 'CHRIS', 'HOPPER', '2022-03-16 13:57:34'),
(133, 'RICHARD', 'PENN', '2006-02-15 03:34:33'),
(134, 'GENE', 'HOPKINS', '2006-02-15 03:34:33'),
(135, 'RITA', 'REYNOLDS', '2006-02-15 03:34:33'),
(136, 'ED', 'MANSFIELD', '2006-02-15 03:34:33'),
(137, 'MORGAN', 'WILLIAMS', '2006-02-15 03:34:33'),
(138, 'LUCILLE', 'DEE', '2006-02-15 03:34:33'),
(139, 'EWAN', 'GOODING', '2006-02-15 03:34:33'),
(140, 'WHOOPI', 'HURT', '2006-02-15 03:34:33'),
(141, 'CATE', 'HARRIS', '2006-02-15 03:34:33'),
(142, 'JADA', 'RYDER', '2006-02-15 03:34:33'),
(143, 'RIVER', 'DEAN', '2006-02-15 03:34:33'),
(144, 'ANGELA', 'WITHERSPOON', '2006-02-15 03:34:33'),
(145, 'KIM', 'ALLEN', '2006-02-15 03:34:33'),
(146, 'ALBERT', 'JOHANSSON', '2006-02-15 03:34:33'),
(147, 'FAY', 'WINSLET', '2006-02-15 03:34:33'),
(148, 'EMILY', 'DEE', '2006-02-15 03:34:33'),
(149, 'RUSSELL', 'TEMPLE', '2006-02-15 03:34:33'),
(150, 'JAYNE', 'NOLTE', '2006-02-15 03:34:33'),
(151, 'GEOFFREY', 'HESTON', '2006-02-15 03:34:33'),
(152, 'BEN', 'HARRIS', '2006-02-15 03:34:33'),
(153, 'MINNIE', 'KILMER', '2006-02-15 03:34:33'),
(154, 'MERYL', 'GIBSON', '2006-02-15 03:34:33'),
(155, 'IAN', 'TANDY', '2006-02-15 03:34:33'),
(156, 'FAY', 'WOOD', '2006-02-15 03:34:33'),
(157, 'GRETA', 'MALDEN', '2006-02-15 03:34:33'),
(158, 'VIVIEN', 'BASINGER', '2006-02-15 03:34:33'),
(159, 'LAURA', 'BRODY', '2006-02-15 03:34:33'),
(160, 'CHRIS', 'DEPP', '2006-02-15 03:34:33'),
(161, 'HARVEY', 'HOPE', '2006-02-15 03:34:33'),
(162, 'OPRAH', 'KILMER', '2006-02-15 03:34:33'),
(163, 'CHRISTOPHER', 'WEST', '2006-02-15 03:34:33'),
(164, 'HUMPHREY', 'WILLIS', '2006-02-15 03:34:33'),
(165, 'AL', 'GARLAND', '2006-02-15 03:34:33'),
(166, 'NICK', 'DEGENERES', '2006-02-15 03:34:33'),
(167, 'LAURENCE', 'BULLOCK', '2006-02-15 03:34:33'),
(168, 'WILL', 'WILSON', '2006-02-15 03:34:33'),
(169, 'KENNETH', 'HOFFMAN', '2006-02-15 03:34:33'),
(170, 'MENA', 'HOPPER', '2006-02-15 03:34:33'),
(171, 'OLYMPIA', 'PFEIFFER', '2006-02-15 03:34:33'),
(172, 'GROUCHO', 'WILLIAMS', '2006-02-15 03:34:33'),
(173, 'ALAN', 'DREYFUSS', '2006-02-15 03:34:33'),
(174, 'MICHAEL', 'BENING', '2006-02-15 03:34:33'),
(175, 'WILLIAM', 'HACKMAN', '2006-02-15 03:34:33'),
(176, 'JON', 'CHASE', '2006-02-15 03:34:33'),
(177, 'GENE', 'MCKELLEN', '2006-02-15 03:34:33'),
(178, 'LISA', 'MONROE', '2006-02-15 03:34:33'),
(179, 'ED', 'GUINESS', '2006-02-15 03:34:33'),
(180, 'JEFF', 'SILVERSTONE', '2006-02-15 03:34:33'),
(181, 'MATTHEW', 'CARREY', '2006-02-15 03:34:33'),
(182, 'DEBBIE', 'AKROYD', '2006-02-15 03:34:33'),
(183, 'RUSSELL', 'CLOSE', '2006-02-15 03:34:33'),
(184, 'HUMPHREY', 'GARLAND', '2006-02-15 03:34:33'),
(185, 'MICHAEL', 'BOLGER', '2006-02-15 03:34:33'),
(186, 'JULIA', 'ZELLWEGER', '2006-02-15 03:34:33'),
(187, 'RENEE', 'BALL', '2006-02-15 03:34:33'),
(188, 'ROCK', 'DUKAKIS', '2006-02-15 03:34:33'),
(189, 'CUBA', 'BIRCH', '2006-02-15 03:34:33'),
(190, 'AUDREY', 'BAILEY', '2006-02-15 03:34:33'),
(191, 'GREGORY', 'GOODING', '2006-02-15 03:34:33'),
(192, 'JOHN', 'SUVARI', '2006-02-15 03:34:33'),
(193, 'BURT', 'TEMPLE', '2006-02-15 03:34:33'),
(194, 'MERYL', 'ALLEN', '2006-02-15 03:34:33'),
(195, 'JAYNE', 'SILVERSTONE', '2006-02-15 03:34:33'),
(196, 'BELA', 'WALKEN', '2006-02-15 03:34:33'),
(197, 'REESE', 'WEST', '2006-02-15 03:34:33'),
(198, 'MARY', 'KEITEL', '2006-02-15 03:34:33'),
(199, 'JULIA', 'FAWCETT', '2006-02-15 03:34:33'),
(200, 'THORA', 'TEMPLE', '2006-02-15 03:34:33');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `actor`
--
ALTER TABLE `actor`
  ADD PRIMARY KEY (`actor_id`),
  ADD KEY `idx_actor_last_name` (`last_name`);

--
-- AUTO_INCREMENT dla zrzuconych tabel
--

--
-- AUTO_INCREMENT dla tabeli `actor`
--
ALTER TABLE `actor`
  MODIFY `actor_id` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=201;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
