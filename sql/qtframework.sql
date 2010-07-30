DROP TABLE IF EXISTS `logs`;


-- -----------------------------------------------------
-- Table `logs`
-- -----------------------------------------------------
CREATE TABLE `logs` (
  `date`           TIMESTAMP           NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `userId`         INT(10) UNSIGNED             DEFAULT NULL,
  `severity`       INT(1)              NOT NULL DEFAULT 5,
  `message`        TEXT                         DEFAULT NULL,
  INDEX `in_logs_date` (`date` ASC)
) ENGINE = InnoDB;

