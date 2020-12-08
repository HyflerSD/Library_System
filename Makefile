.PHONY: clean All

All:
	@echo "----------Building project:[ LibraryAppProject - Debug ]----------"
	@cd "LibraryAppProject" && "$(MAKE)" -f  "LibraryAppProject.mk"
clean:
	@echo "----------Cleaning project:[ LibraryAppProject - Debug ]----------"
	@cd "LibraryAppProject" && "$(MAKE)" -f  "LibraryAppProject.mk" clean
