from platformio.public import PlatformBase

class NuvotonPlatform(PlatformBase):

    def configure_default_packages(self, variables, targets):
        return super().configure_default_packages(variables, targets)

    def get_boards(self, id_=None):
        result = super().get_boards(id_)
        if not result:
            return result
        if id_:
            return self._add_default_debug_tools(result)
        else:
            for key, value in result.items():
                result[key] = self._add_default_debug_tools(value)
        return result