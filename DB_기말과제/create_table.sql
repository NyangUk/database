-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema group11_final_db
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema group11_final_db
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `group11_final_db` DEFAULT CHARACTER SET utf8 ;
USE `group11_final_db` ;

-- -----------------------------------------------------
-- Table `group11_final_db`.`users`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `group11_final_db`.`users` (
  `UserID` INT NOT NULL,
  `UserName` VARCHAR(45) NULL,
  `UserPW` VARCHAR(45) NULL,
  `SV` INT NULL,
  PRIMARY KEY (`UserID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `group11_final_db`.`BigFiles`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `group11_final_db`.`BigFiles` (
  `bigFileID` INT NOT NULL,
  `FileID` INT NULL,
  `DataPath` VARCHAR(45) NULL,
  `UpdatedCount` INT NULL,
  `HOT` INT NULL,
  `UserID` INT NULL,
  PRIMARY KEY (`bigFileID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `group11_final_db`.`MetaData`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `group11_final_db`.`MetaData` (
  `FileID` INT NOT NULL AUTO_INCREMENT, 
  `FileName` VARCHAR(255) NULL,
  `Filesize` INT NULL,
  `ModifyTime` VARCHAR(255) NULL,
  `UserID` INT NULL,
  PRIMARY KEY (`FileID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `group11_final_db`.`SmallFiles`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `group11_final_db`.`SmallFiles` (
  `smallFileID` INT NOT NULL,
  `FileID` INT NULL,
  `DataPath` VARCHAR(45) NULL,
  `UpdatedCount` INT NULL,
  `HOT` INT NULL,
  `UserID` INT NULL,
  PRIMARY KEY (`smallFileID`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
