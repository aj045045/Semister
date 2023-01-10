-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema department
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema department
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `department` DEFAULT CHARACTER SET utf8 ;
USE `department` ;

-- -----------------------------------------------------
-- Table `department`.`role`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`role` (
  `roleid` INT NOT NULL AUTO_INCREMENT,
  `rolename` VARCHAR(15) NULL,
  PRIMARY KEY (`roleid`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`user` (
  `userid` INT NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(10) NULL,
  `mail` VARCHAR(50) NULL,
  `password` VARCHAR(80) NULL,
  `contact_no` VARCHAR(10) NULL,
  `role_roleid` INT NOT NULL,
  PRIMARY KEY (`userid`),
  CONSTRAINT `fk_user_role1`
    FOREIGN KEY (`role_roleid`)
    REFERENCES `department`.`role` (`roleid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`faculty`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`faculty` (
  `facultyid` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `experience` YEAR NULL,
  `specialization` VARCHAR(45) NULL,
  `designation` VARCHAR(45) NULL,
  `email` VARCHAR(60) NULL,
  `contact_no` VARCHAR(13) NULL,
  `role_roleid` INT NOT NULL,
  PRIMARY KEY (`facultyid`),
  CONSTRAINT `fk_faculty_role1`
    FOREIGN KEY (`role_roleid`)
    REFERENCES `department`.`role` (`roleid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`course`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`course` (
  `courseid` INT NOT NULL,
  `coursename` VARCHAR(45) NULL,
  `year` INT NULL,
  PRIMARY KEY (`courseid`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`student`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`student` (
  `studentid` INT NOT NULL AUTO_INCREMENT,
  `studentname` VARCHAR(45) NULL,
  `batch_year` YEAR(4) NULL,
  `semister` INT NULL,
  `email` VARCHAR(70) NULL,
  `contact_no` VARCHAR(10) NULL,
  `course_courseid1` INT NOT NULL,
  `role_roleid` INT NOT NULL,
  PRIMARY KEY (`studentid`),
  CONSTRAINT `fk_student_course1`
    FOREIGN KEY (`course_courseid1`)
    REFERENCES `department`.`course` (`courseid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_student_role1`
    FOREIGN KEY (`role_roleid`)
    REFERENCES `department`.`role` (`roleid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`syllabus`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`syllabus` (
  `syllabusid` INT NOT NULL AUTO_INCREMENT,
  `document` MEDIUMBLOB NULL,
  `semister` INT NULL,
  `course_courseid` INT NOT NULL,
  PRIMARY KEY (`syllabusid`),
  CONSTRAINT `fk_syllabus_course1`
    FOREIGN KEY (`course_courseid`)
    REFERENCES `department`.`course` (`courseid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`categories`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`categories` (
  `cid` INT NOT NULL,
  `category` VARCHAR(45) NULL,
  PRIMARY KEY (`cid`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`event`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`event` (
  `eventid` INT NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(100) NOT NULL,
  `description` VARCHAR(500) NULL,
  `starting` DATETIME NULL,
  `ending` DATETIME NULL,
  `venue` VARCHAR(100) NULL,
  `faculty_facultyid1` INT NOT NULL,
  `student_studentid` INT NOT NULL,
  `categories_cid` INT NOT NULL,
  PRIMARY KEY (`eventid`),
  CONSTRAINT `fk_event_faculty2`
    FOREIGN KEY (`faculty_facultyid1`)
    REFERENCES `department`.`faculty` (`facultyid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_event_student1`
    FOREIGN KEY (`student_studentid`)
    REFERENCES `department`.`student` (`studentid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_event_categories1`
    FOREIGN KEY (`categories_cid`)
    REFERENCES `department`.`categories` (`cid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`research`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`research` (
  `researchid` INT NOT NULL AUTO_INCREMENT,
  `researchyear` YEAR(4) NULL,
  `title` VARCHAR(50) NULL,
  `journal` VARCHAR(100) NULL,
  `publisher` VARCHAR(50) NULL,
  `faculty_facultyid` INT NOT NULL,
  PRIMARY KEY (`researchid`),
  CONSTRAINT `fk_research_faculty1`
    FOREIGN KEY (`faculty_facultyid`)
    REFERENCES `department`.`faculty` (`facultyid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `department`.`award`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `department`.`award` (
  `awardid` INT NOT NULL,
  `awardname` VARCHAR(45) NULL,
  `year` YEAR(4) NULL,
  `association` VARCHAR(50) NULL,
  `faculty_facultyid` INT NOT NULL,
  PRIMARY KEY (`awardid`),
  CONSTRAINT `fk_award_faculty1`
    FOREIGN KEY (`faculty_facultyid`)
    REFERENCES `department`.`faculty` (`facultyid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
