/*
SQLyog Community Edition- MySQL GUI v7.13 
MySQL - 5.1.31-community : Database - lost
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

CREATE DATABASE /*!32312 IF NOT EXISTS*/`lost` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `lost`;

/*Table structure for table `clima` */

DROP TABLE IF EXISTS `clima`;

CREATE TABLE `clima` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `descricao` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

/*Data for the table `clima` */

insert  into `clima`(`id`,`descricao`) values (1,'ensolarado'),(2,'chuvoso'),(3,'nublado'),(4,'tempestade'),(5,'chuviscando'),(6,'com neblina'),(7,'noite'),(8,'de madrugada');

/*Table structure for table `configuracao_usuario` */

DROP TABLE IF EXISTS `configuracao_usuario`;

CREATE TABLE `configuracao_usuario` (
  `id_usuario` varchar(255) NOT NULL,
  `portugues` tinyint(1) NOT NULL DEFAULT '1',
  `ingles` tinyint(1) NOT NULL DEFAULT '1',
  `ordem_antigo_para_recente` tinyint(1) NOT NULL DEFAULT '0',
  `ocultar_lidos` tinyint(1) NOT NULL DEFAULT '0',
  `agrupar_por_tipo` tinyint(1) NOT NULL DEFAULT '1',
  `mostrar_apenas_favoritos` tinyint(1) NOT NULL DEFAULT '0',
  `mostrar_apenas_postagens_de` varchar(255) DEFAULT NULL,
  `id_postagem_aberta` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `configuracao_usuario` */

/*Table structure for table `global` */

DROP TABLE IF EXISTS `global`;

CREATE TABLE `global` (
  `id_grupo_publico` int(11) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `global` */

insert  into `global`(`id_grupo_publico`) values (1);

/*Table structure for table `grupo` */

DROP TABLE IF EXISTS `grupo`;

CREATE TABLE `grupo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `descricao` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

/*Data for the table `grupo` */

insert  into `grupo`(`id`,`descricao`) values (1,'público'),(2,'família'),(3,'amigos'),(4,'VIP'),(6,'English'),(7,'SuperVIP'),(8,'família pai'),(9,'família mãe');

/*Table structure for table `humor` */

DROP TABLE IF EXISTS `humor`;

CREATE TABLE `humor` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `descricao` varchar(255) NOT NULL,
  `imagem` text,
  `descricao_en` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

/*Data for the table `humor` */

insert  into `humor`(`id`,`descricao`,`imagem`,`descricao_en`) values (1,'normal',NULL,'normal'),(2,'feliz',NULL,'happy'),(3,'com saudade',NULL,'with nostalgia'),(4,'apaixonado',NULL,'in love'),(5,'triste',NULL,'sad'),(6,'cansado',NULL,'tired'),(7,'perdido',NULL,'lost'),(8,'ansioso',NULL,'anxious'),(9,'preocupado',NULL,'worried'),(10,'empolgado',NULL,'excited');

/*Table structure for table `lingua` */

DROP TABLE IF EXISTS `lingua`;

CREATE TABLE `lingua` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `descricao` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `lingua` */

insert  into `lingua`(`id`,`descricao`) values (1,'português'),(2,'English');

/*Table structure for table `postagem` */

DROP TABLE IF EXISTS `postagem`;

CREATE TABLE `postagem` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `id_autor` varchar(255) NOT NULL,
  `cidade` varchar(255) DEFAULT NULL,
  `data_publicacao` bigint(20) NOT NULL COMMENT 'timestamp',
  `data_modificada` bigint(20) NOT NULL COMMENT 'timestamp',
  `id_clima` int(10) unsigned DEFAULT NULL,
  `temperatura` double DEFAULT NULL,
  `id_humor` int(10) unsigned DEFAULT NULL,
  `texto` longtext NOT NULL,
  `id_postagem_pai` int(10) unsigned DEFAULT NULL,
  `rascunho` tinyint(1) NOT NULL,
  `id_lingua` int(255) unsigned DEFAULT NULL,
  `titulo` varchar(255) NOT NULL,
  `fuso_horario` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

/*Data for the table `postagem` */

/*Table structure for table `postagem_grupo` */

DROP TABLE IF EXISTS `postagem_grupo`;

CREATE TABLE `postagem_grupo` (
  `id_postagem` int(10) unsigned NOT NULL,
  `id_grupo` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id_postagem`,`id_grupo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `postagem_grupo` */

/*Table structure for table `postagem_usuario` */

DROP TABLE IF EXISTS `postagem_usuario`;

CREATE TABLE `postagem_usuario` (
  `id_postagem` int(10) unsigned NOT NULL,
  `id_usuario` varchar(255) NOT NULL,
  `favorito` tinyint(1) NOT NULL DEFAULT '0',
  `aberto` tinyint(1) NOT NULL DEFAULT '0',
  `lido` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_postagem`,`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `postagem_usuario` */

/*Table structure for table `tags_postagem` */

DROP TABLE IF EXISTS `tags_postagem`;

CREATE TABLE `tags_postagem` (
  `id_postagem` int(10) unsigned NOT NULL,
  `nome_tag` varchar(50) NOT NULL,
  PRIMARY KEY (`id_postagem`,`nome_tag`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `tags_postagem` */

/*Table structure for table `usuario` */

DROP TABLE IF EXISTS `usuario`;

CREATE TABLE `usuario` (
  `email` varchar(255) NOT NULL,
  `senha_md5` char(32) NOT NULL,
  `email_verificado` tinyint(1) NOT NULL DEFAULT '0',
  `data_cadastro` bigint(20) unsigned NOT NULL COMMENT 'timestamp',
  `ultimo_humor` int(10) unsigned DEFAULT NULL,
  `apelido` varchar(255) DEFAULT NULL,
  `codigo_verificacao` int(10) unsigned NOT NULL,
  PRIMARY KEY (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `usuario` */

/*Table structure for table `usuario_grupo` */

DROP TABLE IF EXISTS `usuario_grupo`;

CREATE TABLE `usuario_grupo` (
  `id_usuario` varchar(255) NOT NULL,
  `id_grupo` int(10) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `usuario_grupo` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
