DROP TABLE IF EXISTS `test`;


-- -----------------------------------------------------
-- Table `test`
-- -----------------------------------------------------
CREATE TABLE `test` (
  `column_1` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `column_2` INT(10) UNSIGNED DEFAULT NULL,
  `column_3` TEXT DEFAULT NULL,
  INDEX `key_1` (`column_1` ASC)
) ENGINE = InnoDB;

INSERT INTO `test` VALUES (CURRENT_TIMESTAMP, '1234', 'Message_1');
INSERT INTO `test` VALUES (CURRENT_TIMESTAMP, '5678', 'Message_2');
INSERT INTO `test` VALUES (CURRENT_TIMESTAMP, '90', 'Message_3');
