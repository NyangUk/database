-- create
DROP TRIGGER IF EXISTS `group11_final_db`.`MetaData_AFTER_INSERT`;

DELIMITER $$
USE `group11_final_db`$$
CREATE TRIGGER `MetaData_AFTER_INSERT` AFTER INSERT ON `MetaData` FOR EACH ROW BEGIN
if new.Filesize >10000 then
insert into BigFiles values(new.FileID,new.FileID,new.FileName,0,0,new.UserID);
else 
insert into SmallFiles values(new.FileID,new.FileID,new.FileName,0,0,new.UserID);
END IF;
END$$
DELIMITER ;


-- update
DROP TRIGGER IF EXISTS `group11_final_db`.`MetaData_AFTER_UPDATE`;

DELIMITER $$
USE `group11_final_db`$$
CREATE TRIGGER `MetaData_AFTER_UPDATE` AFTER UPDATE ON `MetaData` FOR EACH ROW BEGIN

declare numB int;
declare numS int;
declare cnt int;
select count(FileID) into numB from BigFiles where new.FileID=BigFiles.FileID;
select count(FileID) into numS from SmallFiles where new.FileID=SmallFiles.FileID;
if numB=1 then
set sql_safe_updates=0;
select UpdatedCount into cnt from BigFiles where new.FileID=BigFiles.FileID;
	if cnt>=4 then
	UPDATE BigFiles SET HOT = (1)where new.FileID=BigFiles.FileID;
	END IF;
	if cnt<4 then
	UPDATE BigFiles SET HOT = (0)where new.FileID=BigFiles.FileID;
	END IF;
UPDATE BigFiles SET UpdatedCount = (cnt+1)where new.FileID=BigFiles.FileID;
elseif numS=1 then
select UpdatedCount into cnt from SmallFiles where new.FileID=SmallFiles.FileID;
	if cnt>=4 then
	UPDATE SmallFiles SET HOT = (1)where new.FileID=SmallFiles.FileID;
	END IF;
	if cnt<4 then
	UPDATE SmallFiles SET HOT = (0)where new.FileID=SmallFiles.FileID;
	END IF;
UPDATE SmallFiles SET UpdatedCount = (cnt+1)where new.FileID=SmallFiles.FileID;
END IF;
END$$
DELIMITER ;

-- delete
DROP TRIGGER IF EXISTS `group11_final_db`.`MetaData_AFTER_DELETE`;

DELIMITER $$
CREATE TRIGGER `MetaData_AFTER_DELETE` AFTER DELETE ON `MetaData` FOR EACH ROW BEGIN
declare numB int;
declare numS int;
select count(FileID) into numB from BigFiles where old.FileID=BigFiles.FileID;
select count(FileID) into numS from SmallFiles where old.FileID=SmallFiles.FileID;
set sql_safe_updates=0;
if numB=1 then
delete from BigFiles where FileID=old.FileID;
elseif numS=1 then
delete from SmallFiles where FileID=old.FileID;
END IF;
END$$
DELIMITER ;
